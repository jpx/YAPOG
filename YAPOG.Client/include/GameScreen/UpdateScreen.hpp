#ifndef YAPOG_CLIENT_UPDATESCREEN_HPP
# define YAPOG_CLIENT_UPDATESCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"

namespace ycl
{
  class UpdateScreen : public BaseScreen
  {
      DISALLOW_COPY(UpdateScreen);

    public:

      UpdateScreen ();
      virtual ~UpdateScreen ();

    protected:

      virtual const yap::ScreenType& HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

    private:

      static const yap::ScreenType DEFAULT_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_UPDATESCREEN_HPP