We are not using digital 0 RX and 1 TX becauuse:

"Digital Pins 0-1/Serial In/Out - TX/RX (dark green) 
-These pins cannot be used for digital i/o (digitalRead and digitalWrite)
if you are also using serial communication (e.g. Serial.begin)."

See: http://arduino.cc/en/reference/board

Only one GUI thread is used in this application. Hence the functions 
bool QIODevice::waitForReadyRead(int msecs) 
bool QIODevice::waitForBytesWritten(int msecs) 

cause a delay the whole GUI. Further, I freeze the GUI when sending pulses, because this is done
using QThread::mSleep() :

		gArduino.HighLow(2,1);
        QThread::msleep(ui->spinBox_pulseDuration_dig2->value());
        gArduino.HighLow(2,0);
		

Hence the next step is to create a second thread.