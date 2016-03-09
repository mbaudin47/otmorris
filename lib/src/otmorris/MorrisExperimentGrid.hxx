//                                               -*- C++ -*-
/**
 *  @file  MorrisExperimentGrid.hxx
 *  @brief MorrisExperimentGrid generates experiments for Morris starting from
 *  grid samples.
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
#ifndef OTMORRIS_MORRISEXPERIMENTGRID_HXX
#define OTMORRIS_MORRISEXPERIMENTGRID_HXX

#include "otmorris/MorrisExperimentImplementation.hxx"

namespace OTMORRIS
{
/**
 * @class MorrisExperiment
 *
 * MorrisExperimentGrid enables to build experiments for the Morris method
 * using full grid input samples
 */
class OTMORRIS_API MorrisExperimentGrid
  : public MorrisExperimentImplementation
{
  CLASSNAME;

public:

  /** Constructor using a p-level grid - Uniform(0,1)^d */
  MorrisExperimentGrid(const OT::Indices & levels, const OT::UnsignedInteger N);

  /** Constructor using a p-level grid and intervals*/
  MorrisExperimentGrid(const OT::Indices & levels, const OT::Interval & interval, const OT::UnsignedInteger N);

  /** Virtual constructor method */
  MorrisExperimentGrid * clone() const;

  /** Generate method */
  OT::NumericalSample generate() const;

  /** String converter */
  OT::String __repr__() const;

  /** get/set jumpStep */
  OT::Indices getJumpStep() const;

  void setJumpStep(const OT::Indices & jumpStep);

  /** Method save() stores the object through the StorageManager */
  virtual void save(OT::Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  virtual void load(OT::Advocate & adv);

protected:

  /** Default constructor for save/load mechanism */
  MorrisExperimentGrid() {};
  friend class OT::Factory<MorrisExperimentGrid>;

private:

  // jumpStep: integers!
  OT::Indices jumpStep_;

}; /* class MorrisExperimentGrid */

} /* namespace OTMORRIS */

#endif /* OTMORRIS_MORRISEXPERIMENTGRID_HXX */
