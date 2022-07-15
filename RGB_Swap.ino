/*
   RGB Swap v 0.1
   by Scott Smith
   2022-7-14

   This sketch will swap between different colors at the push of a button. For now just goes through
   Red, Green, Blue. Later versions will have functionality to cycle through any rainbow colors in any order.
*/

const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;
const int buttonPin = 9;
const int debounceDelay = 50;

int lastButtonState; //1st setup var for comparing button state.
int currentButtonState; //2nd var for comparing button state.
int colorCount; //0 Red, 1 Green, 2 Blue

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  rgbColor(255, 0, 0);
  colorCount = 0;

  currentButtonState = digitalRead(buttonPin);
}

void loop()
{
  //Put code to be repeated here.
  lastButtonState = currentButtonState; //set last state var
  currentButtonState = digitalRead(buttonPin); //read current state

  if (lastButtonState == HIGH && currentButtonState == LOW) //when button is pressed
  {
    if (colorCount == 0) //If LED is Red
    {
      rgbColor(0, 255, 0); //Change color to Green
      colorCount = 1; //Update count var
    }
    else if (colorCount == 1) //If LED is Green
    {
      rgbColor(0, 0, 255); //Set color to Blue
      colorCount = 2; //Update count to match
    }
    else if (colorCount == 2) //If LED is Blue
    {
      rgbColor(255, 0, 0); //Set LED to Red
      colorCount = 0; //Reset count to start loop over
    }

    delay(debounceDelay); //Wait to prevent LED flicker from switch bounce
  }
}

//quick way to set rgb led to specific value
void rgbColor(int red, int green, int blue) //accepts values 0-255
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
