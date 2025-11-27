![CtrlVOZ_a](https://github.com/user-attachments/assets/461fb615-91a2-494c-8181-6c5e92050280)

El siguiente ejemplo, emplearemos un microcontrolador Arduino NANO, un VR3 (Voice Recognition) y un shield SD-Card, para desarrollar un simple control de luces (u otras cosas) por intermedio de nuestra VOZ, pero con un plus extra para hacerlo mas practico: "Cuando indicamos una acción, tenemos una respuesta de nuestro microcontrolador por medio de mensajes de audio "...
Para este proyecto, vamos a requerir descargar e instalar en nuestro IDE las librerias:

_SoftwareSerial.h_
_VoiceRecognitionV3.h_
_SimpleSDAudio.h_

La librería "VoiceRecognitionV3", es para controlar el shield de reconocimiento de voz, y la librería "SimpleSDAudio", sirve para poder reproducir los audios en formato "WAV" que están alojados en la tarjeta SD.
En la imagen anterior, podemos ver que en mi caso particular, como no tenia un micrófono común, implemente un micrófono inalámbrico, y como amplificador para escuchar los mensajes de audio, use un parlante bluetooth con entrada auxiliar...
Como no tengo una voz de locutor, los audios los genere con el traductor de google que permite descargarlos.

Estos audios, hay que editarlos con el siguiente editor on-line: **_Convert audio to WAV_** ( https://audio.online-convert.com/convert-to-wav )

En teoría, según la librería, tenía que convertir los audios en 8bits-mono-16000Khz... Al compilar, cuando reproducía el audio, se escuchaba acelerado.
Se me ocurrió convertirlos en wav de 8bits-mono-16000Khz y al compilar, al momento de reproducir audio, se escuchó perfecto!!!
El circuito para este proyecto, es el siguiente: 

<img width="1600" height="1214" alt="CtrlVOZ_b" src="https://github.com/user-attachments/assets/15dc0365-9b07-48b5-a591-8ccbce431adf" />

Un video corto de como funciona el proyecto: ( https://www.youtube.com/watch?v=W19402g4q_c )

[![CtrlDOMOTICO_VR3](https://img.youtube.com/vi/W19402g4q_c/0.jpg)](https://www.youtube.com/watch?v=W19402g4q_c)
