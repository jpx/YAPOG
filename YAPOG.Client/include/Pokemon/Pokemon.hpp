#ifndef YAPOG_CLIENT_POKEMON_HPP
# define YAPOG_CLIENT_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace yap
{
  class ISprite;
  class PokemonMoveSet;
}

namespace ycl
{
  class PokemonInfo;

  class Pokemon : public yap::Pokemon
  {
    DISALLOW_COPY (Pokemon);

  public:
    Pokemon (const yap::ID& staticID);

    Pokemon (
      const yap::ID& staticID, 
      const yap::UInt16& level, 
      const bool& shiny);

    Pokemon (
      const yap::ID& uniqueID,
      const yap::ID& staticID,
      const yap::String& nickname,
      const yap::PokemonStat& stats,
      const yap::Gender& gender,
      const yap::PokemonStatus& status,
      const bool shiny,
      const yap::Int16& loyalty,
      const yap::PokemonMoveSet& moveSet,
      const yap::ID& natureID,
      const yap::uint& exp,
      const yap::UInt8& boxNumber,
      const yap::ID& boxIndex,
      const yap::String& catchDate);

    virtual ~Pokemon ();

    /// Getters
    yap::ISprite& GetIcon () const;
    yap::ISprite& GetGenderIcon () const;
    yap::ISprite& GetBattleBack () const;
    yap::ISprite& GetBattleFront () const;

  private:
    void Init ();
    void LoadSprites ();

    yap::ISprite* icon_;
    yap::ISprite* genderIcon_;
    yap::ISprite* battleBack_;
    yap::ISprite* battleFront_;

    PokemonInfo* graphicPokemonInfo_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMON_HPP

