#include <SFML\Graphics\Text.hpp>

#include "YAPOG\Graphics\Gui\Label.hpp"
#include "YAPOG\Graphics\IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

namespace yap
{
  Label::Label ()
    : textContent_ ()
    , drawableText_ ()
  {
  }

  Label::Label (String content)
    : textContent_ (content)
    , drawableText_ (content)
  {
    /*drawableText_.setPosition (Vector2 (GetPosition ().x + padding_->left,
    GetPosition ().y + padding_->top));*/
    drawableText_.setPosition (GetPosition ().x,
      GetPosition ().y - drawableText_.getCharacterSize ()
      + drawableText_.getGlobalBounds ().height);
  }

  Label::~Label ()
  {
  }

  float Label::GetCharWidth () const
  {
    return drawableText_.getCharacterSize () / 1.5;
  }

  Vector2 Label::CharPos (uint pos) const
  {
    return drawableText_.findCharacterPos (pos);
  }

  uint Label::Length () const
  {
    return textContent_.length ();
  }
  Vector2 Label::HandleGetSize () const
  {
    return Vector2 (padding_->left
      + drawableText_.getGlobalBounds ().width
      + padding_->right,
      padding_->top
      + drawableText_.getGlobalBounds ().height
      + padding_->bottom)
      + ((border_ != nullptr) ? Vector2 (border_->GetWidth ()
      * 2, border_->GetWidth () * 2) : Vector2 ());
  }

  void Label::HandleDraw (IDrawingContext& context)
  {
    context.Draw (drawableText_);
  }

  void Label::HandleShow (bool isVisible)
  {
  }

  void Label::HandleMove (const Vector2& offset)
  {
    drawableText_.move (offset);
    //drawableText_.setPosition (GetPosition() + offset);
  }

  void Label::HandleScale (const Vector2& factor)
  {
    drawableText_.setScale (factor);
  }

  void Label::HandleUpdate (const Time& dt)
  {
  }

  void Label::HandleChangeColor (const sf::Color& color)
  {
    drawableText_.setColor (color);
  }

  String Label::GetText () const
  {
    return textContent_;
  }

  void Label::SetText (String& content)
  {
    if (content.empty())
      return;
    else if (content == textContent_)
      return;

    textContent_ = content;
    drawableText_.setString (content);
    /* drawableText_.setPosition (Vector2 (GetPosition ().x + padding_->left,
    GetPosition ().y + padding_->top));*/
    drawableText_.setPosition (GetPosition ().x,
      GetPosition ().y - drawableText_.getCharacterSize ()
      + drawableText_.getGlobalBounds ().height);
    OnTextChanged (*this, EventArgsString (content));
  }
} // namespace yap