#include "fish.hpp"
#include <cassert>


namespace Penna
{

  // Definition of static data members
  age_type Fish::maturity_age_ = 0;

  void Fish::set_maturity_age( age_type r )
  {
    maturity_age_ = r;
  }

  /// Default constructor: Uses all good genome.
  Fish::Fish()
    :   gen_()
    ,   age_(0)
  {
  }

  /// Constructor using a given genome.
  Fish::Fish( const Genome& gen )
    :   gen_(gen)
    ,   age_(0)
  {
  }

  bool Fish::is_dead() const
  {
    return age_ > maximum_age || gen_.count_bad(age_) > gen_.get_bad_threshold();
  }

  bool Fish::is_pregnant() const
  {
    return (age_ > maturity_age_);
  }

  age_type Fish::age() const
  {
    return age_;
  }
	
  void Fish::grow()
  {
    assert( !is_dead() );
    ++age_;
  }

  Fish Fish::give_birth() const
  {
    assert( is_pregnant() == true );
    Genome child_genome=gen_;
    child_genome.mutate();
    return Fish( child_genome );
  }

  const Genome& Fish::genome() const
  {
    return gen_;
  }
  
} // end namespace Penna
