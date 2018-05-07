# ======================= ofxCMake Vers. 0.1 =============
#  PUT THIS FILE INTO YOUR OPENFRAMEWORKS PROJECT FOLDER

# ========================================================
# ===================== CMake Settings ===================
# ========================================================
cmake_minimum_required( VERSION 3.3 )
project( openframeworks )

# ========================================================
# ===================== User Settings ====================
# ========================================================
# ---------------------- App name  -----------------------
set( APP_NAME   ledCylinder )

# ------------------------ OF Path -----------------------
# --- If outside the OF structure, set an absolute OF path
set( OF_DIRECTORY_BY_USER "/Users/cassm/src/openFrameworks 0.9.8" )

# --------------------- Source Files ---------------------
set( ${APP_NAME}_SOURCE_FILES
        src/main.cpp
        src/ofApp.cpp
        src/ledCylinder.cpp
        src/ledMapper.cpp
        src/ledSender.cpp )


# ------------------------ AddOns  -----------------------
set( OFX_ADDONS_ACTIVE
        #        ofxXmlSettings
        #        ofxOsc
        #        ofxGui
        #        ofxNetwork
        #        ofxVectorGraphics
        #        ofxThreadedImageLoader
        #        ofxAssimpModelLoader
        #        ofxKinect
        #        ofxOpenCv
        #        ofxSvg
        #        ofxEmscripten (untested)
                )

# =========================================================================
# ============================== OpenFrameworks ===========================
# =========================================================================
include( ${OF_DIRECTORY_BY_USER}/addons/ofxCMake/modules/main.cmake )
# =========================================================================

include_directories("/usr/local/Cellar/boost/1.67.0_1/include/boost")

