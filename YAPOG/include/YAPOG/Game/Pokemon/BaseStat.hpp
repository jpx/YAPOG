#ifndef YAPOG_BASESTAT_HPP
# define YAPOG_BASESTAT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class YAPOG_LIB BaseStat
  {
    DISALLOW_COPY (BaseStat);

    public:
      BaseStat ();
      BaseStat (const UInt16& value);
      BaseStat (const UInt16& value, const UInt16& iv, const UInt16& ev);

      const UInt16& GetValue () const;
      const UInt16& GetIndividualValue () const;
      const UInt16& GetEffortValue () const;

      virtual void SetValue (const UInt16& value);
      void SetIndividualValue (const UInt16& iv);
      void SetEffortValue (const UInt16& ev);

  protected:
    UInt16 value_;
    UInt16 individualValue_;
    UInt16 effortValue_;

  private:
    static const UInt16 INITIAL_STAT_VALUE;
    static const UInt16 INITIAL_INDIVIDUAL_VALUE;
    static const UInt16 INITIAL_EFFORT_VALUE;
  };
} // namespace yap

#endif // YAPOG_BASESTAT_HPP