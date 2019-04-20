// var pounds = prompt("Enter the weight in pounds?");
// alert("That is " + pounds*0.454 + " kilograms!");
// console.log("Conversion Completed");

var first = prompt("What is your first name?");
var last = prompt("What is your last name?");
var age = prompt("How old are you?");
var height = prompt("How tall are you (cm)?");
var pet = prompt("What is the name of your pet?");
var endPet = pet[pet.length-1];

if (first[0] == last[0] && age>20 && age<30 && height>=170 && endPet==='y') {
  console.log("Welcome comrade!!");
}
else {
  console.log("Nothing to see here.");
}
