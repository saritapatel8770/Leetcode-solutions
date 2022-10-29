/* Sorts the array in ascending order */
int sortFunc(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}

void helper(int* candidates, int candidatesSize, int target, int index, int* current, int currentLength, int* returnSize, int** returnColumnSizes, int*** answer) {
    /* Track the previous candidate to avoid duplicate solutions*/
    int prevCan = 0;
    
    /* Loop through all possible candidates to add to the solution */
    for (int i = index; i < candidatesSize; i++) {
        
        /* If the candidate matches the target, add to the answer */
        if (candidates[i] == target) {
            (*returnSize)++;
            
            /* Allocate memory for new answer */
            *answer = (int**)realloc(*answer, (*returnSize) * sizeof(int*));
            (*answer)[(*returnSize) - 1] = (int*)malloc((currentLength+1) * sizeof(int));
            
            /* Copy data into new answer */
            memcpy((*answer)[(*returnSize) - 1], current, currentLength * sizeof(int));
            (*answer)[(*returnSize) - 1][currentLength] = candidates[i];
            
            /* Update the returnColumnSizes array */
            (*returnColumnSizes) = (int*)realloc((*returnColumnSizes), (*returnSize) * sizeof(int));
            (*returnColumnSizes)[(*returnSize) - 1] = currentLength + 1;
            
            /* Break to avoid duplicate answers */
            /* Since the candidates are sorted, any next candidates will be too large */
            break;
        }
        
        /* If the candidate could possibly work, add it to the current answer and recursively call the helper */
        else if (candidates[i] <= (target / 2) && candidates[i] != prevCan) {
            current[currentLength] = candidates[i];
            helper(candidates, candidatesSize, target - candidates[i], i + 1, current, currentLength + 1, returnSize, returnColumnSizes, answer);
            prevCan = candidates[i];
        }
        
        /* Since the list is sorted, break once the candidate is too large */
        else if (candidates[i] > target) break;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    
    /* Sort the candidates to group duplicates together */
    qsort(candidates, candidatesSize, sizeof(int), sortFunc);
    
    /* Array to store the current solution */
    int* current = (int*)malloc(100*sizeof(int));
    int currentLength = 0;
    
    /* Allocate initial memory to answer and returnColumnSizes */
    int** answer = (int**)malloc(sizeof(int*));
    (*returnColumnSizes) = (int*)malloc(sizeof(int));
    
    (*returnSize) = 0;
    
    /* Call the helper with our initial conditions */
    helper(candidates, candidatesSize, target, 0, current, currentLength, returnSize, returnColumnSizes, &answer);
    
    free(current);
    return answer;
}