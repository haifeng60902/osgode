/*!
 * @file Picker.cpp
 * @author Rocco Martino
 */
/***************************************************************************
 *   Copyright (C) 2013 by Rocco Martino                                   *
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
#include <osgODEUtil/Picker>

#include <osgODE/CommonRayCastResults>
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
/* ....................................................................... */
/* ======================================================================= */




using namespace osgODEUtil ;




/* ======================================================================= */
/* ....................................................................... */
Picker::Picker(void):
    m_ray_cast_result   ( new osgODE::NearestRayCastResult() )
{
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
Picker::Picker(const Picker& other, const osg::CopyOp& copyop):
    osg::Object             ( other, copyop ),
    m_space                 ( other.m_space ),
    m_camera                ( other.m_camera ),
    m_ray_cast_result       ( new osgODE::NearestRayCastResult() )
{
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
Picker::~Picker(void)
{
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
osgODE::Collidable*
Picker::pick( const osg::Vec2& ndc )
{
    osg::Vec3   tmp ;

    return pick( ndc, tmp ) ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
osgODE::Collidable*
Picker::pick( const osg::Vec2& ndc, osg::Vec3& point )
{
    osg::Vec3   ray_from, ray_to ;

    computeRay( ndc, ray_from, ray_to ) ;


    m_ray_cast_result->reset() ;


    m_space->performRayCast( ray_from, ray_to, m_ray_cast_result, 128 ) ;

    point.set( m_ray_cast_result->getPosition() ) ;


    return m_ray_cast_result->getCollidable() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
void
Picker::computeRay( const osg::Vec2& ndc, osg::Vec3& ray_from, osg::Vec3& ray_to )
{
    const osg::Matrix&      view = m_camera->getViewMatrix() ;
    const osg::Matrix&      proj = m_camera->getProjectionMatrix() ;


    const osg::Matrix   inv_vp = osg::Matrix::inverse( view * proj ) ;


    ray_from.set( osg::Vec3( ndc.x(), ndc.y(), -1.0 ) * inv_vp ) ;
    ray_to.set( osg::Vec3( ndc.x(), ndc.y(),  1.0 ) * inv_vp ) ;
}
/* ....................................................................... */
/* ======================================================================= */
