#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Game/Pokemon/HitPoint.hpp"

#include "Gui/PokemonHPBarWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  const sf::Color PokemonHPBarWidget::
    DEFAULT_HP_COLOR_GOOD = sf::Color (110, 250, 170);
  const sf::Color PokemonHPBarWidget::
    DEFAULT_HP_COLOR_MEDIUM = sf::Color (250, 225, 50);
  const sf::Color PokemonHPBarWidget::
    DEFAULT_HP_COLOR_BAD = sf::Color (250, 90, 60);

  const float PokemonHPBarWidget::MAX_HP_BAR_SIZE = 144.f;

  PokemonHPBarWidget::PokemonHPBarWidget ()
    : hp_ (nullptr)
    , hpBarContent_ (nullptr)
    , mainLayout_ (nullptr)
  {
    mainLayout_ = new yap::HorizontalLayout (
      yap::Padding (45, 0, 0, 6), yap::Padding (), false);
    hpBarContent_ = new yap::PictureBox ();
  }

  void PokemonHPBarWidget::Init ()
  {
    SetSize (yap::Vector2 (195, 21));

    SetBackground (*new yap::WidgetBackground (
      "Pictures/Battle/HPBattleBar.png", true));

    hpBarContent_->SetPicture (new yap::Sprite (
      "Pictures/Battle/HPBarContent.png"));

    mainLayout_->SetSize (GetSize ());

    mainLayout_->AddChild (*hpBarContent_, yap::LayoutBox::Align::TOP);

    AddChild (*mainLayout_);
  }

  void PokemonHPBarWidget::SetHitPoint (const yap::HitPoint& hp)
  {
    if (hp_ == nullptr)
    {
      hp_ = &hp;
      Update ();
    }
    else
      YAPOG_THROW("HP have already been set !");
  }

  void PokemonHPBarWidget::Update ()
  {
    // Update the color
    /*
    /// Red: -1.4x + 250
    int red = (-1.4f) * value + 250;
    /// Green: 2x + 50
    int green = 2 * value + 50;
    /// Blue: 1.2x + 50
    int blue = 1.2f * value + 50;

    hpBarContent_->ChangeColor (sf::Color (
    yap::MathHelper::Clamp (red, 0, 255),
    yap::MathHelper::Clamp (green, 0, 255),
    yap::MathHelper::Clamp (blue, 0, 255)));
    */

    if (hp_->GetHPPercentage () * 100 <= 25)
      hpBarContent_->ChangeColor (DEFAULT_HP_COLOR_BAD);
    else if (hp_->GetHPPercentage () * 100 <= 50)
      hpBarContent_->ChangeColor (DEFAULT_HP_COLOR_MEDIUM);
    else
      hpBarContent_->ChangeColor (DEFAULT_HP_COLOR_GOOD);

    // Update the size
    float size =  MAX_HP_BAR_SIZE * hp_->GetHPPercentage ();

    hpBarContent_->SetSize (yap::Vector2 (
      size,
      hpBarContent_->GetSize ().y));
  }

  bool PokemonHPBarWidget::IsFocusable () const
  {
    return false;
  }

  void PokemonHPBarWidget::HandleMove (const yap::Vector2& offset)
  {
  }

  void PokemonHPBarWidget::HandleScale (const yap::Vector2& factor)
  {
  }
  void PokemonHPBarWidget::HandleDraw (yap::IDrawingContext& offset)
  {
  }

  void PokemonHPBarWidget::HandleShow (bool isVisible)
  {
  }

  void PokemonHPBarWidget::HandleChangeColor (const sf::Color& color)
  {
  }

  void PokemonHPBarWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
