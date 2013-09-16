/*!
 * @file HingeServoMotor.cpp
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
#include <osgODE/HingeServoMotor>
#include <osgODE/HingeJoint>
#include <osgODE/World>
#include <osgODE/Notify>
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
/* ....................................................................... */
/* ======================================================================= */




using namespace osgODE ;




/* ======================================================================= */
/* ....................................................................... */
HingeServoMotor::HingeServoMotor(void):
    m_position      ( 0.0 ),
    m_force         ( 0.0 ),
    m_gain          ( 1.0 )
{
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
HingeServoMotor::HingeServoMotor(const HingeServoMotor& other, const osg::CopyOp& copyop):
    ODECallback     ( other,  copyop),
    m_position      ( other.m_position ),
    m_force         ( other.m_force ),
    m_gain          ( other.m_gain )
{
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
HingeServoMotor::~HingeServoMotor(void)
{
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
void
HingeServoMotor::operator()(ODEObject* object)
{

    HingeJoint*     hinge = object->asHingeJoint() ;
    PS_ASSERT1( hinge != NULL ) ;

    World*      world = object->getWorld() ;
    PS_ASSERT1( world != NULL ) ;


    const double    err = m_position - hinge->getAngle() ;
    const double    gain = m_gain / world->getCurrentStepSize() ;
    const double    vel = gain * err ;

    hinge->setParam( dParamFMax, m_force ) ;
    hinge->setParam( dParamVel, vel ) ;


    traverse(object) ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
HingeServoMotor*
HingeServoMotor::asHingeServoMotor(void)
{
    return this ;
}
/* ....................................................................... */
/* ======================================================================= */