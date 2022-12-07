s.fc = 10e3;
fs = 100e3;
t = (0:1/fs:0.01)';
Create a two-tone sinusoidal signal with frequencies 300 and 600 Hz.
s = sin(2*pi*300*t)+2*sin(2*pi*600*t);
Create a lowpass filter.
[num,den] = butter(10,fc*2/fs);
Amplitude modulate the signal s.
y = ammod(s,fc,fs);
Demodulate the received signal.
z = amdemod(y,fc,fs,0,0,num,den);
plot(t,s,'c',t,z,'b--')
legend('Original Signal','Demodulated Signal')
xlabel('Time (s)')
ylabel('Amplitude')
