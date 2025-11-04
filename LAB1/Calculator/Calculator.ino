
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial); //wait for serial monitor to open
  Serial.println("input a calculation like: 8+4");
}

void loop() {
  //If Input is available then read data
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); //store input until enter was pressed
    char op;
    float num1, num2, result;
    
    unsigned int data = sscanf(input.c_str(), "%f %c %f", &num1, &op, & num2); //store input in individual variabels
    //calculate and store results
    if (data == 3) {
      switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
          if (num2 != 0) {
            result = num1 / num2;
          } else {
            Serial.println("Error: Division by zero!");
            return;
          }
          break;
        default: 
          Serial.println("Invalid oparetor!");
      }
      //display result
      Serial.println("Result:");
      Serial.println(result);
      Serial.println("Enter the Next calculaiton");
    }
    else {
      Serial.println("invalid input");
    }
    
  }
}
