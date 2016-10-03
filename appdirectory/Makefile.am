noinst_HEADERS = TutorialApplication.h BaseApplication.h Physics.h MyMotionState.h BulletEntities.h

bin_PROGRAMS = assignment2
assignment2_CPPFLAGS = -I$(top_srcdir)
assignment2_SOURCES = TutorialApplication.cpp BaseApplication.cpp Physics.cpp MyMotionState.cpp BulletEntities.cpp
assignment2_CXXFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(bullet_CFLAGS) $(CEGUI_CFLAGS)
assignment2_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(bullet_LIBS) $(CEGUI_LIBS) $(CEGUI_OGRE_LIBS)
assignment2_LDFLAGS = -lOgreOverlay -lboost_system

EXTRA_DIST = buildit makeit
AUTOMAKE_OPTIONS = foreign
