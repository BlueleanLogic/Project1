noinst_HEADERS = TutorialApplication.h BaseApplication.h Physics.h MyMotionState.h BulletEntities.h Sound.h

bin_PROGRAMS = assignment2
assignment2_CPPFLAGS = -I$(top_srcdir)
assignment2_SOURCES = TutorialApplication.cpp BaseApplication.cpp Physics.cpp MyMotionState.cpp BulletEntities.cpp Sound.cpp
assignment2_CXXFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(bullet_CFLAGS) $(CEGUI_CFLAGS) $(sdl_CFLAGS) $(SDLMIXER_CFLAGS)
assignment2_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(bullet_LIBS) $(CEGUI_LIBS) $(CEGUI_OGRE_LIBS) $(sdl_LIBS) $(SDLMIXER_LIBS)
assignment2_LDFLAGS = -lOgreOverlay -lboost_system

EXTRA_DIST = buildit makeit
AUTOMAKE_OPTIONS = foreign
