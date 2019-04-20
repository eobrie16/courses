var player1 = prompt("Player One: Enter your name, you will be blue");
var player1Color = 'rgb(86, 151, 255)';

var player2 = prompt("Player Two: Enter your name, you will be red");
var player2Color = 'rgb(237, 45, 73)'

var done = false;

header = $('h3');
table = $('tr');
cells = $('td');

function reportWin(row, col) {
  console.log("You won starting at row, col");
  console.log(row);
  console.log(col);
}

function changeColor(row, col, color) {
  return table.eq(row).find('td').eq(col).find('button').css('background-color',color);
}

function getColor(row, col) {
  return table.eq(row).find('td').eq(col).find('button').css('background-color');
}

function checkBottom(col) {
  var colorReport = getColor(5, col);
  for (var i = 5; i > -1; i--) {
    colorReport = getColor(i, col);
    if (colorReport === 'rgb(128, 128, 128)') {
      return i
    }
  }
}

function colorMatchCheck(one,two,three,four) {
  return (one === two && one === three && one === four && one != 'rgb(128, 128, 128)' && one !== undefined)
}

// Check for Horizontal Wins
function horizontalWinCheck() {
  for (var row = 0; row < 6; row++) {
    for (var col = 0; col < 4; col++) {
      if (colorMatchCheck(getColor(row,col), getColor(row,col+1) ,getColor(row,col+2), getColor(row,col+3))) {
        console.log('horiz');
        reportWin(row,col);
        return true;
      }else {
        continue;
      }
    }
  }
}

// Check for Vertical Wins
function verticalWinCheck() {
  for (var col = 0; col < 7; col++) {
    for (var row = 0; row < 3; row++) {
      if (colorMatchCheck(getColor(row,col), getColor(row+1,col) ,getColor(row+2,col), getColor(row+3,col))) {
        console.log('vertical');
        reportWin(row,col);
        return true;
      }else {
        continue;
      }
    }
  }
}

// Check for Diagonal Wins
function diagonalWinCheck() {
  for (var col = 0; col < 5; col++) {
    for (var row = 0; row < 7; row++) {
      if (colorMatchCheck(getColor(row,col), getColor(row+1,col+1) ,getColor(row+2,col+2), getColor(row+3,col+3))) {
        console.log('diag');
        reportWin(row,col);
        return true;
      }else if (colorMatchCheck(getColor(row,col), getColor(row-1,col+1) ,getColor(row-2,col+2), getColor(row-3,col+3))) {
        console.log('diag');
        reportWin(row,col);
        return true;
      }else {
        continue;
      }
    }
  }
}


var currentPlayer = 1;
var currentName = player1;
var currentColor = player1Color;

$('h3').text(currentName + " it is your turn.")

$('.board button').on('click', function(){

  var col = $(this).closest('td').index();
  var bottomAvail = checkBottom(col);
  changeColor(bottomAvail,col,currentColor);

  if (horizontalWinCheck || verticalWinCheck || diagonalWinCheck) {
    $('h1').text(currentName + " You have won!");
    $('h3').fadeOut('fast');
    $('h2').fadeOut('fast');
  }

  currentPlayer = currentPlayer * -1;
  if (currentPlayer === 1) {
    currentName = player1;
    currentColor = player1Color;
  } else {
    currentName = player2;
    currentColor = player2Color;
  }
  $('h3').text(currentName + " it is your turn.")

})
