/*!
 * @file ShockWave.inl
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
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _OSGODE_SHOCKWAVE_INL
#define _OSGODE_SHOCKWAVE_INL




/* ======================================================================= */
/* ....................................................................... */
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ShockWave::setDirection( const osg::Vec3& direction )
{
    m_direction = direction ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osg::Vec3&
osgODE::ShockWave::getDirection(void)
{
    return m_direction ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline const osg::Vec3&
osgODE::ShockWave::getDirection(void) const
{
    return m_direction ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ShockWave::setAngle( double angle )
{
    m_angle = osg::clampTo(angle, 0.0, osg::PI) ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline double
osgODE::ShockWave::getAngle(void) const
{
    return m_angle ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ShockWave::setSpeed( double speed )
{
    m_speed = osg::maximum(0.0, speed) ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline double
osgODE::ShockWave::getSpeed(void) const
{
    return m_speed ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ShockWave::setImpulse( double impulse )
{
    m_impulse = osg::maximum(0.0, impulse) ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline double
osgODE::ShockWave::getImpulse(void) const
{
    return m_impulse ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ShockWave::setLinearAttenuation( double linear_attenuation )
{
    m_linear_attenuation = osg::maximum(0.0, linear_attenuation) ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline double
osgODE::ShockWave::getLinearAttenuation(void) const
{
    return m_linear_attenuation ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ShockWave::setQuadraticAttenuation( double quadratic_attenuation )
{
    m_quadratic_attenuation = osg::maximum(0.0, quadratic_attenuation) ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline double
osgODE::ShockWave::getQuadraticAttenuation(void) const
{
    return m_quadratic_attenuation ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ShockWave::setThreshold( double threshold )
{
    m_threshold = osg::maximum( 0.0, threshold ) ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline double
osgODE::ShockWave::getThreshold(void) const
{
    return m_threshold ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline void
osgODE::ShockWave::setWaveSize( double wave_size )
{
    m_wave_size = osg::maximum( 0.0, wave_size ) ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline double
osgODE::ShockWave::getWaveSize(void) const
{
    return m_wave_size ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline double
osgODE::ShockWave::getCurrentForce(void) const
{
    return m_current_force ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline double
osgODE::ShockWave::getCurrentRadius(void) const
{
    return m_current_radius ;
}
/* ....................................................................... */
/* ======================================================================= */









#endif /* _OSGODE_SHOCKWAVE_INL */