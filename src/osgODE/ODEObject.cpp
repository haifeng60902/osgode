/*!
 * @file ODEObject.cpp
 * @author Rocco Martino
 */
/***************************************************************************
 *   Copyright (C) 2010 - 2012 by Rocco Martino                            *
 *   martinorocco@gmail.com                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation; either version 2.1 of the  *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Lesser General Public License for more details.                   *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/* ======================================================================= */
/* ....................................................................... */
#include <osgODE/ODEObject>
#include <osgODE/World>
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
/* ....................................................................... */
/* ======================================================================= */




using namespace osgODE ;




/* ======================================================================= */
/* ....................................................................... */
unsigned int    ODEObject::s_last_id = 0 ;
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
ODEObject::ODEObject(void):
    m_ID(0)
{
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
ODEObject::ODEObject(const ODEObject& other, const osg::CopyOp& copyop):
    osg::Object(other, copyop),
    m_update_callback(other.m_update_callback),
    m_post_update_callback(other.m_post_update_callback),
    m_ID(0),
    m_user_object( other.m_user_object.get() ),
    m_interacting_sphere(other.m_interacting_sphere)
{
    if( copyop.getCopyFlags() & osg::CopyOp::DEEP_COPY_CALLBACKS ) {
        if( other.m_update_callback.valid() ) {
            m_update_callback = osg::clone( other.m_update_callback.get(), copyop ) ;
        }

        if( other.m_post_update_callback.valid() ) {
            m_post_update_callback = osg::clone( other.m_post_update_callback.get(), copyop ) ;
        }

        if( other.m_interaction_callback.valid() ) {
            m_interaction_callback = osg::clone( other.m_interaction_callback.get(), copyop ) ;
        }
    }
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
ODEObject::~ODEObject(void)
{
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
void
osgODE::ODEObject::setWorldInternal(World* world)
{
    m_world = world ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
void
ODEObject::setIDInternal(unsigned int id)
{
    m_ID = id ;
    s_last_id = osg::maximum(s_last_id, id) ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
unsigned int
ODEObject::generateID(void)
{
    m_ID = ++s_last_id ;

    return m_ID ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
void
ODEObject::update(double step_size)
{
    (void) step_size ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
void
ODEObject::postUpdate(double step_size)
{
    (void) step_size ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
bool
ODEObject::addToWorldInternal(World* world)
{
    (void) world ;

    return true ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
bool
ODEObject::removeFromWorldInternal(World* world)
{
    (void) world ;

    return true ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
void
ODEObject::accept(osg::NodeVisitor& nv)
{
    (void) nv ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
const osg::BoundingSphere&
ODEObject::getBound(void) const
{
    return m_bounding_sphere ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
void
ODEObject::callUpdateCallbackInternal(void)
{
    if( m_update_callback.valid() ) {
        (*m_update_callback)(this) ;
    }
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
void
ODEObject::callPostUpdateCallbackInternal(void)
{
    if( m_post_update_callback.valid() ) {
        (*m_post_update_callback)(this) ;
    }
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
#define AS_NULL( NAME ) NAME* ODEObject::as##NAME(void) { return NULL ; }

AS_NULL( BypassJoint ) ;
AS_NULL( CharacterBase) ;
AS_NULL( Collidable) ;
AS_NULL( Container) ;
AS_NULL( FixedJoint) ;
AS_NULL( HingeJoint) ;
AS_NULL( Joint ) ;
AS_NULL( NoGravityVolume ) ;
AS_NULL( ODEObjectContainer ) ;
AS_NULL( RigidBody ) ;
AS_NULL( ShockWave ) ;
AS_NULL( Space ) ;
AS_NULL( Transformable ) ;
AS_NULL( UniversalJoint ) ;
AS_NULL( World ) ;

#undef AS_NULL
/* ....................................................................... */
/* ======================================================================= */
