//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        17/04/2012
// \brief		Attaching Specific Properties to Meshes
//
//--------------------------------------------------------------------------------//
#include "lcProperty.h"
//--------------------------------------------------------------------------------//

Property::Property()
{

}

//--------------------------------------------------------------------------------//

Property::~Property()
{

}

//--------------------------------------------------------------------------------//

LC_PROPERTY_TYPES Property::GetType()
{
	return m_eType;
}

//--------------------------------------------------------------------------------//