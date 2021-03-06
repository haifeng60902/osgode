/*!
 * @file ODEObject.inl
 * @author Rocco Martino
 */
/***************************************************************************
 *   Copyright (C) 2010 - 2014 by Rocco Martino                            *
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

#ifndef _OSGODE_ODEOBJECT_INL
#define _OSGODE_ODEOBJECT_INL

/* ======================================================================= */
/* ....................................................................... */
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ODEObject::setUpdateCallback(osgODE::ODECallback* cbk)
{
    m_update_callback = cbk ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osgODE::ODECallback*
osgODE::ODEObject::getUpdateCallback(void)
{
    return m_update_callback.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline const osgODE::ODECallback*
osgODE::ODEObject::getUpdateCallback(void) const
{
    return m_update_callback.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ODEObject::addUpdateCallback(osgODE::ODECallback* cbk)
{
    if( m_update_callback.valid() ) {
        m_update_callback->addNestedCallback(cbk) ;
    } else {
        setUpdateCallback(cbk) ;
    }
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ODEObject::removeUpdateCallback(osgODE::ODECallback* cbk)
{
    if(cbk) {
        if( cbk == m_update_callback.get()) {
            m_update_callback = m_update_callback->getNestedCallback() ;
        } else {
            if( m_update_callback.valid() ) {
                m_update_callback->removeNestedCallback(cbk) ;
            }
        }
    }
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ODEObject::setPostUpdateCallback(osgODE::ODECallback* cbk)
{
    m_post_update_callback = cbk ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osgODE::ODECallback*
osgODE::ODEObject::getPostUpdateCallback(void)
{
    return m_post_update_callback.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline const osgODE::ODECallback*
osgODE::ODEObject::getPostUpdateCallback(void) const
{
    return m_post_update_callback.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ODEObject::addPostUpdateCallback(osgODE::ODECallback* cbk)
{
    if( m_post_update_callback.valid() ) {
        m_post_update_callback->addNestedCallback(cbk) ;
    } else {
        setPostUpdateCallback(cbk) ;
    }
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ODEObject::removePostUpdateCallback(osgODE::ODECallback* cbk)
{
    if(cbk) {
        if( cbk == m_post_update_callback.get()) {
            m_post_update_callback = m_post_update_callback->getNestedCallback() ;
        } else {
            if( m_post_update_callback.valid() ) {
                m_post_update_callback->removeNestedCallback(cbk) ;
            }
        }
    }
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline unsigned int
osgODE::ODEObject::getID(void) const
{
    return m_ID ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osgODE::World*
osgODE::ODEObject::getWorld(void)
{
    return m_world.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline const osgODE::World*
osgODE::ODEObject::getWorld(void) const
{
    return m_world.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ODEObject::setUserObject(osg::Object* obj)
{
    m_user_object = obj ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osg::Object*
osgODE::ODEObject::getUserObject(void)
{
    return m_user_object.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline const osg::Object*
osgODE::ODEObject::getUserObject(void) const
{
    return m_user_object.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline const osg::BoundingSphere&
osgODE::ODEObject::getActorBound(void) const
{
    return m_actor_bound ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ODEObject::setActorBound(const osg::BoundingSphere& bs)
{
    m_actor_bound.set( bs.center(), bs.radius() ) ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline bool
osgODE::ODEObject::getActor(void) const
{
    return m_actor ;
}
/* ....................................................................... */
/* ======================================================================= */




#endif /* _OSGODE_ODEOBJECT_INL */
