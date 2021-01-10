let nums = [2,7,8,9,10,13,17,19,21];

// *arrays must be sorted

//Iterative Method

/*function binarySearch(arr, target) {
  let left = 0;
  let right = arr.length - 1;
	let mid;

  while(left <= right) {
     mid = Math.floor(right - left);
     if (arr[mid] === target) {
     	return mid;
     } else if (arr[mid] > target) {
     	right = mid - 1;
     } else {
     	left = mid + 1;
     }
  }

  return false;

}


*/

// Time complexity: O(log n)
// Space complexity: O(1)


//Recursive method

function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    return binarySearchHelper(arr, target, left, right);
}

function binarySearchHelper(arr, target, left, right) {
    if (left > right) return false;

    let mid = Math.floor(right - left);

    if (arr[mid] === target) return mid;
    else if (arr[mid] < target) return binarySearchHelper(arr, target, mid + 1, right);
    else return binarySearchHelper(arr, target, left, mid - 1);
}

// Time complexity: O(log n)
// Space complexity: O(log n)

console.log(binarySearch(nums, 7)); // return 1
console.log(binarySearch(nums, 1)); // return false
console.log(binarySearch(nums, 13)); // return 5