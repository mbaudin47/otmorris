//                                               -*- C++ -*-
/**
 *  @file  MyClassImplementation.cxx
 *  @brief MyClassImplementation
 *
 *  Copyright 2005-2015 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License.
 *
 *  This library is distributed in the hope that it will be useful
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 *  @author: schueller
 */
#include "MyClassImplementation.hxx"
#include "PersistentObjectFactory.hxx"

using namespace OT;

namespace OTTEMPLATE
{

CLASSNAMEINIT(MyClassImplementation);

static Factory<MyClassImplementation> RegisteredFactory;


/* Default constructor */
MyClassImplementation::MyClassImplementation()
  : PersistentObject()
{
  // Nothing to do
}

/* Virtual constructor method */
MyClassImplementation * MyClassImplementation::clone() const
{
  return new MyClassImplementation(*this);
}

/* example of a func that return a point squared. */
NumericalPoint MyClassImplementation::square(NumericalPoint& p) const
{

  NumericalPoint p_out(p.getSize());
  for(UnsignedInteger i = 0; i < p.getSize(); ++ i)
  {
    p_out[i] = p[i] * p[i];
  }
  return p_out;
}

/* String converter */
String MyClassImplementation::__repr__() const
{
  OSS oss;
  oss << "class=" << MyClassImplementation::GetClassName();
  return oss;
}

/* Method save() stores the object through the StorageManager */
void MyClassImplementation::save(Advocate & adv) const
{
  PersistentObject::save( adv );
}

/* Method load() reloads the object from the StorageManager */
void MyClassImplementation::load(Advocate & adv)
{
  PersistentObject::load( adv );
}


} /* namespace OTTEMPLATE */
