/*
 * Physics3D.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: sushil
 */

#include <Physics3D.h>
#include <Entity381.h>
#include <Utils.h>

Physics3D::Physics3D(FlyingEntity381 * ent, AspectType aType): Physics2D((Entity381*) ent, aType) {
	// TODO Auto-generated constructor stub
	flyingEntity = ent;
}

Physics3D::~Physics3D() {
	// TODO Auto-generated destructor stub
}


void Physics3D::Tick(float dt){
	Physics2D::Tick(dt);
	
	flyingEntity->desiredAltitude = Clamp(flyingEntity->minAltitude, flyingEntity->maxAltitude, flyingEntity->desiredAltitude);
	if(flyingEntity->desiredAltitude < flyingEntity->altitude){
		flyingEntity->altitude -= flyingEntity->climbRate * dt;
	} else if (flyingEntity->desiredAltitude > flyingEntity->altitude){
		flyingEntity->altitude += flyingEntity->climbRate * dt;
	}
	flyingEntity->altitude = Clamp(flyingEntity->minAltitude, flyingEntity->maxAltitude, flyingEntity->altitude);
	flyingEntity->position.y = flyingEntity->altitude;
}
