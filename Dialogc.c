#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include "Dialogc.h"
#include "ParameterManager.c"

JNIEXPORT jint JNICALL Java_Dialogc_PM_1parse(JNIEnv * env, jobject Dialogc, jlong table, jstring file, jchar comment){
	const char * fname = (*env)->GetStringUTFChars(env, file, NULL);
	FILE * fp = fopen((char*)fname, "r");
	int flag = 0;
	ParameterList * list;
	ParameterList * name;
	flag = PM_parseFrom((ParameterManager*)table, fp, comment);
	if(flag!=0){
		list = PM_getValue((ParameterManager*)table, "buttons").list_val;
		list = list->next;
		while(list!=NULL){
			if(name->data!=NULL){
				PM_manage((ParameterManager*)table, list->data, 3, 1);
			}
			list = list->next;
		}
		name = PM_getValue((ParameterManager*)table, "fields").list_val;
		name = name->next;
		while(name!=NULL){
			if(name->data!=NULL){
				PM_manage((ParameterManager*)table, name->data, 3, 1);
			}
			name = name->next;
		}
		flag = PM_parseFrom((ParameterManager*)table, fp, comment);
	}
	fclose(fp);
	(*env)->ReleaseStringUTFChars(env, file, fname);
	return(flag);
}

JNIEXPORT jlong JNICALL Java_Dialogc_PM_1create(JNIEnv *env, jobject Dialogc, jint size){
	ParameterManager * manage;
	manage = PM_create(size);
	return((long)manage);
}

JNIEXPORT jint JNICALL Java_Dialogc_PM_1destroy(JNIEnv *env, jobject Dialogc, jlong table){
	int flag;
	flag = PM_destroy((ParameterManager*)table);
	return(flag);
}

JNIEXPORT jint JNICALL Java_Dialogc_PM_1manage(JNIEnv *env, jobject Dialogc, jlong table, jstring pname, jint type, jint required){
	const char * name = (*env)->GetStringUTFChars(env, pname, NULL);
	int flag;
	flag = PM_manage((ParameterManager*)table, (char*)name, type, required);
	(*env)->ReleaseStringUTFChars(env, pname, name);
	return(flag);
}

JNIEXPORT jobjectArray JNICALL Java_Dialogc_PM_1getList(JNIEnv *env, jobject Dialogc, jlong table, jstring pname){
	const char * name = (*env)->GetStringUTFChars(env, pname, NULL);
	ParameterList * head;
	ParameterList * curr;
	jobjectArray ret = NULL;
	int i = 0;
	int j = 0;
	head = PM_getValue((ParameterManager*)table, (char*)name).list_val;
	(*env)->ReleaseStringUTFChars(env, pname, name);
	head = head->next;
	curr = head;
	while(curr!=NULL){
		i++;
		curr = curr->next;
	}
	char * array[i];
	curr = head;
	for(j=0; j<i; j++){
		if(curr->data!=NULL){
			array[j] = curr->data;
		}
		curr = curr->next;
	}
	jclass stringClass = (*env)->FindClass(env,("java/lang/String"));
	ret = (jobjectArray)(*env)->NewObjectArray(env, i, stringClass, NULL);
	for(j=0; j<i; j++){
		(*env)->SetObjectArrayElement(env, ret, j, (*env)->NewStringUTF(env,array[j]));
	}
	return(ret);
}

JNIEXPORT jstring JNICALL Java_Dialogc_PM_1getString(JNIEnv *env, jobject Dialogc, jlong table, jstring pname){
	const char * name = (*env)->GetStringUTFChars(env, pname, NULL);
	char * strVal;
	jstring answer;
	strVal = PM_getValue((ParameterManager*)table, (char*)name).str_val;
	(*env)->ReleaseStringUTFChars(env, pname, name);
	answer = (*env)->NewStringUTF(env, (const char*)strVal);
	return answer;
}
