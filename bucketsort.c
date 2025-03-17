#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 10000

typedef struct node{
	char* string;
	struct node* next;
} node;

typedef struct bucket{
	char* min_word;
	node* head;
} bucket;

int main(int argc, char* argv[]){
	if(argc<2){
		printf("bucketsort: Fatal error! there must be at-least one CLA.\n");
		return 1;
	}
	
	for(int i = 1; i<argc; i++){
		if(i != argc - 1){
			if(strcmp(argv[i], argv[i + 1]) > 0){
				printf("bucketsort: Fatal error! CLAs must be entered in alphabetical order\n");
				return 1;
			}
		}
	}
	
	bucket* buckets = (bucket*)malloc(argc * sizeof(bucket));
	buckets[0].min_word = ""; //always empty string for the min_word of first
	buckets[0].head = NULL;
	
	for(int i = 1; i < argc; i++){
		buckets[i].min_word = argv[i];
		buckets[i].head = NULL;
	}
	
	//Read the keyboard(stdin)
	
	char* line = (char*)malloc(MAX_LEN);
	if(!fgets(line, MAX_LEN, stdin)){
		printf("stdin is empty!\n");
		return 1;
		
	}
	
	if(line[strlen(line)-1] == '\n')
		line[strlen(line)-1] = '\0';
	
	char* word[MAX_LEN];		//Array to store words during tokenization with MAX size
	char* input_string = strtok(line, " "); 	//tokenizes when space is encountered
	
	
	word[0] = input_string;						//first element in word array
	int counter = 0;							//counter unmber of words im the input_string
	while(input_string != NULL){
		word[counter] = (char*)malloc(strlen(input_string)+1);
		strcpy(word[counter], input_string);
		input_string = strtok(NULL, " ");
		counter++;
	}
	
	for(int i = 0; i < argc; i++){
		node* current = (node*)malloc(sizeof(node));
		current = buckets[i].head;
		for(int j = 0; j < counter; j++){
			if(i != argc-1){
				if((strcasecmp(word[j], buckets[i].min_word) > 0 || strcasecmp(word[j], buckets[i].min_word) == 0) && strcasecmp(word[j], buckets[i + 1].min_word) < 0){
					node * word_node = (node*)malloc(sizeof(node));
					word_node->string = word[j];
					
					if(buckets[i].head == NULL){
						buckets[i].head = word_node;
						buckets[i].head->next = NULL;
					}
					
					else if(buckets[i].head->next == NULL && strcasecmp(word[j], buckets[i].head->string) > 0){
						buckets[i].head->next = word_node;
					}
					
					else if(buckets[i].head->next == NULL && strcasecmp(word[j], buckets[i].head->string) < 0){
						word_node->next = buckets[i].head;
						buckets[i].head = word_node;
					}
					
					else{
						node* current = buckets[i].head;
						while(current->next != NULL && strcasecmp(word[j], current->next->string) >= 0){
							current = current->next;
						}
						word_node->next = current->next;
						current->next = word_node;
					}
					
					
				}
			}
			else{
				if(strcasecmp(word[j], buckets[i].min_word) > 0 || strcasecmp(word[j], buckets[i].min_word) == 0){
					node* word_node = (node*)malloc(sizeof(node));
					word_node->string = word[j];
					
					if(buckets[i].head == NULL){
						buckets[i].head = word_node;
						buckets[i].head->next = NULL;
					}
					
					else if(buckets[i].head->next == NULL && strcasecmp(word[j], buckets[i].head->string) > 0){
						buckets[i].head->next = word_node;
					}
					
					else if (buckets[i].head->next == NULL && strcasecmp(word[j], buckets[i].head->string) < 0){
						word_node->next = buckets[i].head;
						buckets[i].head = word_node;
					}
					
					else{
						node* current = buckets[i].head;
						while(current->next != NULL && strcasecmp(word[j], current->next->string) >= 0){
							current = current->next;
						}
						word_node->next = current->next;
						current->next = word_node;
					}
				}
			}
		}
		
		
		
		
			if(buckets[i].head != NULL){
			printf("bucket %d: ", i);
			node* temp = buckets[i].head;
			while(temp != NULL){
				printf("%s ", temp->string);
				temp = temp->next;
			}
				printf("\n");
			}		
			
			
	}
	free(line);
	free(buckets);
	free(input_string);
  


	return 0;

}

			
	
