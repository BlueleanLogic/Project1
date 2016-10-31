noinst_HEADERS = GameManager.h BaseApplication.h Physics.h MyMotionState.h Sound.h GUI.h NetManager.h Paddle.h

bin_PROGRAMS = assignment3
assignment3_CPPFLAGS = -I$(top_srcdir)
assignment3_SOURCES = GameManager.cpp BaseApplication.cpp Physics.cpp MyMotionState.cpp Sound.cpp GUI.cpp NetManager.cpp Paddle.cpp
assignment3_CXXFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(bullet_CFLAGS) $(CEGUI_CFLAGS) $(sdl_CFLAGS) $(SDLMIXER_CFLAGS) $(SDLNET_CFLAGS)
assignment3_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(bullet_LIBS) $(CEGUI_LIBS) $(CEGUI_OGRE_LIBS) $(sdl_LIBS) -lSDL_net $(SDLMIXER_LIBS) $(SDLNET_LIBS)
assignment3_LDFLAGS = -lOgreOverlay -lboost_system

EXTRA_DIST = buildit makeit
AUTOMAKE_OPTIONS = foreign
