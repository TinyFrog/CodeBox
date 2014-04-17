/*

In which case the output would be an array looking something like:

    [ 'node', '/path/to/your/program.js', '1', '2', '3' ]

You'll need to think about how to loop through the number arguments so  you can output just their sum. The first element of the process.argv array is always 'node', and the second element is always the path to your program.js file, so you need to start at the 3rd element (index 2), adding each item to the total until you reach the end of the array.

Also be aware that all elements of process.argv are strings and you may need to coerce them into numbers. You can do this by prefixing the property with + or passing it to Number(). e.g. +process.argv[2] or Number(process.argv[2]).


*/

counter = 0;
sum = 0;
var arr = process.argv

// The variable in foo/in loop is INDEX!
for(var index in arr){
    if(counter > 1){
        sum += +arr[index];
    }
    counter++;
}
console.log(sum);
