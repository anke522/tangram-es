
#include <jni.h>
#include "tangram.h"

extern "C" {
	JNIEXPORT void JNICALL Java_com_mapzen_tangram_Tangram_init(JNIEnv* jniEnv, jobject obj) 
	{
		initializeOpenGL();
	}

	JNIEXPORT void JNICALL Java_com_mapzen_tangram_Tangram_resize(JNIEnv* jniEnv, jobject obj, jint width, jint height) 
	{
		resizeViewport(width, height);
	}

	JNIEXPORT void JNICALL Java_com_mapzen_tangram_Tangram_render(JNIEnv* jniEnv, jobject obj) 
	{
		renderFrame();
	}

    JNIEXPORT void JNICALL Java_com_mapzen_tangram_Tangram_handleGestures(JNIEnv* jniEnv, jobject obj, jint gestureType, jfloat posOrVelx, jfloat posOrVely, jfloat scale) {
        switch(gestureType) {
            case 0:
                handleGestures(Tangram::Gestures::Tap, glm::vec2(posOrVelx, posOrVely));
                break;
            case 1:
                handleGestures(Tangram::Gestures::DoubleTap, glm::vec2(posOrVelx, posOrVely));
                break;
            case 2:
                handleGestures(Tangram::Gestures::Pan, glm::vec2(posOrVelx, posOrVely));
                break;
            case 3:
                handleGestures(Tangram::Gestures::Pinch, glm::vec2(posOrVelx, posOrVely), scale);
                break;
            default:
                handleGestures(Tangram::Gestures::Invalid);
        }
    }
}

