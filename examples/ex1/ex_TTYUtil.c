#include "ex_TTYUtil.h"
#include <unistd.h>
#include <string.h>

JNIEXPORT jstring JNICALL Java_ex_TTYUtil_getTTYName
  (JNIEnv *env, jclass cls)
{
    char *name = ttyname(STDOUT_FILENO);
    return (*env)->NewStringUTF(env, name);
}

JNIEXPORT jboolean JNICALL Java_ex_TTYUtil_isTTY
  (JNIEnv *env, jclass cls)
{
    return isatty(STDOUT_FILENO)? JNI_TRUE: JNI_FALSE;
}

JNIEXPORT jstring JNICALL Java_ex_TTYUtil_getReptition
  (JNIEnv *env, jclass cls, jstring inJNIStr, jint counter) {
  	char output[8192];
  	output[0] = 0;

	const char *inCStr = (*env)->GetStringUTFChars(env, inJNIStr, NULL);
	if (NULL == inCStr) return NULL;

	// Step 2: Perform its intended operations
	printf("In C, the received string is: %s\n", inCStr);

	// if(counter > 0) {
	// 	strcpy(&output[0], inCStr);
	// }
		// sprintf(&output[0], "%s%s\n", &output[0], inCStr);
	for(;counter>0;counter--) {
		sprintf(&output[0], "%s%s\n", &output[0], inCStr);
	}

	(*env)->ReleaseStringUTFChars(env, inJNIStr, inCStr);  // release resources

	// Step 3: Convert the C-string (char*) into JNI String (jstring) and return
	return (*env)->NewStringUTF(env, output);
}

JNIEXPORT jdouble JNICALL Java_ex_TTYUtil_getAvg
  (JNIEnv *env, jclass obj, jdoubleArray inJNIdoubleArray) {

	// jdouble *inCArray = (*env)->GetDoubleArrayElements(env, inJNIdoubleArray, NULL);
	// if (NULL == inCArray) return 0;
	// jsize length = (*env)->GetArrayLength(env, inJNIdoubleArray);

	// jdouble sum = 0;
	// for(int i=0;i<length;i++) {
	// 	sum += inCArray[i];
	// 	inCArray[i] *= 2;
	// }
  	
	// (*env)->ReleaseDoubleArrayElements(env, inJNIdoubleArray, inCArray, 0);
 //  	sum /= length;

	// double *d = (double*) (*env)->GetDirectBufferAddress(env, (jobject) inJNIdoubleArray);
	// jdouble sum = 0;
	// for(int i=0;i<100;i++) {
	// 	sum += d[i];
	// 	d[i] *= 2;
	// }
	// sum /= 100;


	double *d = (double*) (*env)->GetPrimitiveArrayCritical(env, inJNIdoubleArray, NULL);
	jsize length = (*env)->GetArrayLength(env, inJNIdoubleArray);
	jdouble sum = 0;
	for(int i=0;i<length;i++) {
		sum += d[i];
		d[i] *= 2;
	}
	sum /= length;
	(*env)->ReleasePrimitiveArrayCritical(env, inJNIdoubleArray, d, 0);
  	return sum;
}
