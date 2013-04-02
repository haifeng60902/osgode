#include <osgODE/Manager>
#include <osgODE/Space>
#include <osgODE/Box>
#include <osgODE/TriMesh>
#include <osgODE/AerodynamicDevice>
#include <osgODE/Notify>

#include <osgODEUtil/CreateTriMeshFromNode>

#include <osgDB/WriteFile>
#include <osgDB/ReadFile>




#ifndef OSGODE_DATA_PATH
#define OSGODE_DATA_PATH "../../data/export"
#endif




int
main(int argc, char** argv)
{
    osgDB::Registry::instance()->getDataFilePathList().push_back( OSGODE_DATA_PATH ) ;


    osg::Node*      cube = osgDB::readNodeFile("companioncube.osgb") ;

    PS_ASSERT1( cube != NULL ) ;




    /*
     * [1] Create the manager
     */
    osg::ref_ptr<osgODE::Manager>   manager = new osgODE::Manager() ;

    manager->setup(false, true, 1.0/100.0) ;

    manager->setWorld( new osgODE::Space() ) ;


    manager->getWorld()->setWind( osg::Vec3(-1.0, 0.0, 0.0) ) ;




    /*
     * [3] Create a kinematic plane as floor
     */
    {
        osg::Node*  plane = osgDB::readNodeFile( "floor.osgb" ) ;

        PS_ASSERT1( plane != NULL ) ;



        // build the motionless trimesh
        osgODE::TriMesh*    trim = osgODEUtil::createTriMeshFromNode(plane) ;

        trim->setKinematic(true) ;


        // add the trimesh to the space
        manager->getWorld()->addObject(trim) ;

        // add the graphic node to the simulation
        trim->getMatrixTransform()->addChild(plane) ;
    }




    /*
     * [4] Create a dynamic cube without an aerodynamic device
     */
    {
        osgODE::Collidable*     box = new osgODE::Box() ;
        box->setSize( osg::Vec3(1, 1, 1) ) ;

        // graphics
        box->getMatrixTransform()->addChild(cube) ;

        // move the cube to the left
        box->setPosition( osg::Vec3(-4, 0.0, 10.0) ) ;

        // insert the cube into the world
        manager->getWorld()->addObject(box) ;
    }




    /*
     * [5] Create a cube with an aerodynamic device
     */
    {
        osgODE::Collidable*     box = new osgODE::Box() ;
        box->setSize( osg::Vec3(1, 1, 1) ) ;

        // graphics
        box->getMatrixTransform()->addChild(cube) ;

        // move the cube to the right
        box->setPosition( osg::Vec3(4, 0.0, 10.0) ) ;

        // insert the cube into the world
        manager->getWorld()->addObject(box) ;



        // setup the aerodynamic device
        const double    CX = 2.0 ;

        box->addUpdateCallback( new osgODE::AerodynamicDevice(CX) ) ;
    }




    /*
     * [6] write out the graph
     */
    osgDB::writeNodeFile(*manager, "output.osgb") ;




    // bye
    return 0 ;
}
