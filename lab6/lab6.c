#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 1024

struct listing {
	int id, host_id, minimum_nights, number_of_reviews, calculated_host_listings_count,availability_365;
	char *host_name, *neighbourhood_group, *neighbourhood, *room_type;
	float latitude, longitude, price;
};

struct listing getfields(char* line){
	struct listing item;

	/* Note: you have to pass the string to strtok on the first 
	   invocation and then pass NULL on subsequent invocations */
	item.id = atoi(strtok(line, ","));
	item.host_id = atoi(strtok(NULL, ","));
	item.host_name = strdup(strtok(NULL, ","));
	item.neighbourhood_group = strdup(strtok(NULL, ","));
	item.neighbourhood = strdup(strtok(NULL, ","));
	item.latitude = atof(strtok(NULL, ","));
	item.longitude = atof(strtok(NULL, ","));
	item.room_type = strdup(strtok(NULL, ","));
	item.price = atof(strtok(NULL, ","));
	item.minimum_nights = atoi(strtok(NULL, ","));
	item.number_of_reviews = atoi(strtok(NULL, ","));
	item.calculated_host_listings_count = atoi(strtok(NULL, ","));
	item.availability_365 = atoi(strtok(NULL, ","));
	
	return item;
}

void displayStruct(struct listing item) {
	printf("ID : %d\n", item.id);
	printf("Host ID : %d\n", item.host_id);
	printf("Host Name : %s\n", item.host_name);
	printf("Neighbourhood Group : %s\n", item.neighbourhood_group);
	printf("Neighbourhood : %s\n", item.neighbourhood);
	printf("Latitude : %f\n", item.latitude);
	printf("Longitude : %f\n", item.longitude);
	printf("Room Type : %s\n", item.room_type);
	printf("Price : %f\n", item.price);
	printf("Minimum Nights : %d\n", item.minimum_nights);
	printf("Number of Reviews : %d\n", item.number_of_reviews);
	printf("Calculated Host Listings Count : %d\n", item.calculated_host_listings_count);
	printf("Availability_365 : %d\n\n", item.availability_365);
}
//Comparison function for sorting by host name
int compareHostName(const void *x, const void *y) {
	struct listing *listingX = (struct listing *)x;
	struct listing *listingY = (struct listing *)y;
	return strcmp(listingX->host_name, listingY->host_name);
}

// Comparison function for sorting by price
int comparePrice(const void *x, const void *y) {
	struct listing *listingX = (struct listing *)x;
	struct listing *listingY = (struct listing *)y;
	if (listingX->price < listingY->price){
		return -1;
	} 
	else if (listingX->price > listingY->price){
		return 1;
	}
	else{
		return 0;
	}
}

void writeToFile(struct listing *listings, int count, char *filename) {
	FILE *file = fopen(filename, "w");
	if (file == NULL) {
		printf("Error opening file %s\n", filename);
		exit(-1);
	}
	for (int i = 0; i < count; i++) {
		fprintf(file, "%d,%d,%s,%s,%s,%f,%f,%s,%f,%d,%d,%d,%d\n",
			listings[i].id, listings[i].host_id, listings[i].host_name,
			listings[i].neighbourhood_group, listings[i].neighbourhood,
			listings[i].latitude, listings[i].longitude, listings[i].room_type,
			listings[i].price, listings[i].minimum_nights, listings[i].number_of_reviews,
			listings[i].calculated_host_listings_count, listings[i].availability_365);
	}
	fclose(file);
}

int main(int argc, char* args[]) {
	struct listing list_items[22555];
	char line[LINESIZE];
	int i, count;

	FILE *fptr = fopen("listings.csv", "r");
	if(fptr == NULL){
		printf("Error reading input file listings.csv\n");
		exit (-1);
	}

	count = 0;
	while (fgets(line, LINESIZE, fptr) != NULL){
		list_items[count++] = getfields(line);
	}
	fclose(fptr);
	
	qsort(list_items, count, sizeof(struct listing), compareHostName);
	writeToFile(list_items, count, "sortedByHostName.csv");

	qsort(list_items, count, sizeof(struct listing), comparePrice);
	writeToFile(list_items, count, "sortedByPrice.csv");
	
	return 0;
}
