void bounds2(char* str) {
	char *tmp=getenv("HOME");
	if(tmp!=NULL){
		strcpy(str,tmp);
	}
	return;
}
