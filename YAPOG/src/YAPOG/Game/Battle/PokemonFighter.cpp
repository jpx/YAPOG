#include "YAPOG/Game/Battle/PokemonFighter.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Pokemon/HitPoint.hpp"

namespace yap
{
  PokemonFighter::PokemonFighter (Pokemon* originalPokemon)
    : originalPokemon_ (originalPokemon)
    , stats_ (PokemonStat (originalPokemon_->GetStats ()))
  {
    if (originalPokemon == nullptr)
      YAPOG_THROW("The original Pokemon doesn't exist !");
  }

  /// @name IBattleEntity members
  /// @{
  const String& PokemonFighter::GetName () const
  {
    return originalPokemon_->GetName ();
  }

  const PokemonExperience& PokemonFighter::GetExperience () const
  {
    return originalPokemon_->GetExperience ();
  }

  UInt16 PokemonFighter::GetLevel () const
  {
    return originalPokemon_->GetLevel ();
  }

  Gender PokemonFighter::GetGender () const
  {
    return originalPokemon_->GetGender ();
  }

  UInt16 PokemonFighter::GetCurrentHP () const
  {
    return stats_.GetHitPoint ().GetCurrentValue ();
  }

  UInt16 PokemonFighter::GetMaxHP () const
  {
    return stats_.GetHitPoint ().GetValue ();
  }

  float PokemonFighter::GetHPPercentage () const
  {
    return  ((float)GetCurrentHP () / (float)GetMaxHP ()) * 100;
  }

  const PokemonStat& PokemonFighter::GetStats () const
  {
    return stats_;
  }

  const TypeInfo& PokemonFighter::GetType1 () const
  {
    return originalPokemon_->GetType1 ();
  }

  const TypeInfo& PokemonFighter::GetType2 () const
  {
    return originalPokemon_->GetType2 ();
  }

  float PokemonFighter::GetTypeEffectFactor (const TypeInfo& type) const
  {
    return originalPokemon_->GetTypeEffectFactor (type);
  }

  const Attack& PokemonFighter::GetAttack () const
  {
    return stats_.GetAttack ();
  }

  const Defense& PokemonFighter::GetDefense () const
  {
    return stats_.GetDefense ();
  }

  const SpecialAttack& PokemonFighter::GetSpecialAttack () const
  {
    return stats_.GetSpecialAttack ();
  }
  const SpecialDefense& PokemonFighter::GetSpecialDefense () const
  {
    return stats_.GetSpecialDefense ();
  }

  const Speed& PokemonFighter::GetSpeed () const
  {
    return stats_.GetSpeed ();
  }

  void PokemonFighter::AddExperience (int value)
  {
    const PokemonExperience& oldValue = originalPokemon_->GetExperience ();

    originalPokemon_->AddExperience (value);
  }

  void PokemonFighter::TakeDamage (int value)
  {
    SetCurrentHP (GetCurrentHP () - value);
  }

  const PokemonMoveSet& PokemonFighter::GetMoveSet () const
  {
    return originalPokemon_->GetMoveSet ();
  }

  const PokemonMove& PokemonFighter::GetMove (int index) const
  {
    return *originalPokemon_->GetMoveSet ().GetMove (index);
  }

  /// @}

  // Private setters.
  void PokemonFighter::SetCurrentHP (int value)
  {
    if (value < 0)
      value = 0;

    const HitPoint& oldValue = stats_.GetHitPoint ();
    stats_.SetCurrentHP (value);
  }

  void PokemonFighter::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  void PokemonFighter::HandleUpdate (const Time& dt)
  {
  }

} // namespace yap