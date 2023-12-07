#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Network{
	int input[2];
	int hidden[2];
	int output[1];
	int w1,w2,w3,w4,w5,w6;
};
double sigmoid(double x){
	return 1 / (1 + exp(-x));
}
void init_weight(struct Network n){
	n.w1 = rand()*1.0/RAND_MAX;
	n.w2 = rand()*1.0/RAND_MAX;
	n.w3 = rand()*1.0/RAND_MAX;
	n.w4 = rand()*1.0/RAND_MAX;
	n.w5 = rand()*1.0/RAND_MAX;
	n.w6 = rand()*1.0/RAND_MAX;
}
void train(struct Network n, int *input, int *output){
	//FeedForward
	hidden[0] = sigmoid(w1*input[0]+w2*input[1]);
	hidden[1] = sigmoid(w3*input[0]+w4*input[1]);
	output[0] = sigmoid(w5*hidden[0]+w6*hidden[1]);
}
int main(){
	
	return 0;
}