#include <stdio.h>

int solution(int arr[], int length) {
  int max = arr[0];
  int answer = 0;

  // Tim so lon thu 2 va gan cho bien answer
  for (int i = 0; i < length; i++) {
    if (arr[i] < max) {
      answer = arr[i];
      break;
    }
  }

  for (int i = 0; i < length; i++) {
    if (arr[i] > max) {
      answer = max;
      max = arr[i];
    }
    else if (arr[i] > answer && arr[i] < max) {
      answer = arr[i];
    }
  }

  return answer;
}

int main() {
 int arr[] = {1,2,3,4,5,6,7,8,9};
 int length = 9;
 int answer = solution(arr, length);
 printf("%d\n", answer);
}