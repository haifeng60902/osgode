/*!
 * @file ControllerBase.inl
 * @author Rocco Martino
 */
/***************************************************************************
 *   Copyright (C) 2012 - 2013 by Rocco Martino                            *
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

#ifndef _OSGODEUTIL_CONTROLLERBASE_INL
#define _OSGODEUTIL_CONTROLLERBASE_INL

/* ======================================================================= */
/* ....................................................................... */
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osgODEUtil::Signal3<const int, const int, bool>*
osgODEUtil::ControllerBase::onKeyPressed(void)
{
    return m_on_key_pressed.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osgODEUtil::Signal3<const int, const int, bool>*
osgODEUtil::ControllerBase::onKeyReleased(void)
{
    return m_on_key_released.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osgODEUtil::Signal2<const bool, bool>*
osgODEUtil::ControllerBase::onLeftMouseButton(void)
{
    return m_on_left_button.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osgODEUtil::Signal2<const bool, bool>*
osgODEUtil::ControllerBase::onMiddleMouseButton(void)
{
    return m_on_middle_button.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osgODEUtil::Signal2<const bool, bool>*
osgODEUtil::ControllerBase::onRightMouseButton(void)
{
    return m_on_right_button.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osgODEUtil::Signal2<const bool, bool>*
osgODEUtil::ControllerBase::onMouseWheel(void)
{
    return m_on_mouse_wheel.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osgODEUtil::Signal2<const osg::Vec2, bool>*
osgODEUtil::ControllerBase::onMouseMoved(void)
{
    return m_on_mouse_moved.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




/* ======================================================================= */
/* ....................................................................... */
inline osgODEUtil::Signal3<bool, osg::Vec2, bool>*
osgODEUtil::ControllerBase::onFrame(void)
{
    return m_on_frame.get() ;
}
/* ....................................................................... */
/* ======================================================================= */




#endif /* _OSGODEUTIL_CONTROLLERBASE_INL */
