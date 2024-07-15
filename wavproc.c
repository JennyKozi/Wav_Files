// MODE = 1, 2, 3, 4, 5, 6, 7

#include <stdio.h>
#include <math.h>
#include <fcntl.h>

void calc(int, int);
void printchar(char, char, char, char);
void printint(int, int, int, int);
void calcsample(short);
void mysound(int, int, double, double, double, double);

int main(void) {

	char riff1, riff2, riff3, riff4; // The 4 bytes that represent 'RIFF' (riff1 is the first char for RIFF etc)
	int SizeOfFile;	// For SizeOfFile the byte "file1" is the first byte we read
	int file1, file2, file3, file4; // According to Little Endian: file1-->least important byte, file4-->most important byte
	char wave1, wave2, wave3, wave4; // The 4 bytes that represent 'WAVE'
	char fmt1, fmt2, fmt3, fmt4; // The 4 bytes that represent 'fmt ' (format chunk)
	int SizeOfFormat; // The case of SizeOfFile applies to all of the variables that must be calculated with the big-endian prototype
	int format1, format2, format3, format4;	// The 4 bytes of SizeOfFormat
	int WAVEformat;
	int wave_format1, wave_format2;	// The 2 bytes of WAVEformat
	int MonoStereo;
	int mono1, mono2; // The 2 bytes of MonoStereo
	int SampleRate;
	int sample1, sample2, sample3, sample4; // The 4 bytes of SampleRate
	int BytesPerSec;
	int bytes1, bytes2, bytes3, bytes4; // The 4 bytes of BytesPerSec
	int BlockAlign;
	int block1, block2; // The 4 bytes of BlockAlign
	int BitsPerSample;
	int bits1, bits2; // The 2 bytes of BitsPerSample
	char data1, data2, data3, data4; // The 4 bytes that represent 'data'
	int SizeOfData = 0;
	int size1, size2, size3, size4; // The 4 bytes of SizeOfData
	int ch, n = 1, i = 0, j = 2, d = 0;
	int nbytes = 0, newSizeOfFile;
	short Sample; // A Sample of sound
 
	#ifdef WIN32
	_setmode (_fileno (stdout), O_BINARY);
	_setmode (_fileno (stdin), O_BINARY);
	#endif

	if (MODE != 7) {
		// Loop for the first 44 bytes of the file
		while ((ch = getchar()) != EOF) {
			nbytes++;  /* Count the total bytes */
			switch (nbytes) {
			// RIFF (the first 4 bytes represent 'RIFF')
				case 1: riff1 = ch;
					break;
				case 2: riff2 = ch;
					break;
				case 3: riff3 = ch;
					break;
				case 4: riff4 = ch;
					break;
			// Size of File (Bytes: 5-8)
				case 5: file1 = ch;
					break;
				case 6: file2 = ch;
					break;
				case 7: file3 = ch;
					break;
				case 8: file4 = ch;
					SizeOfFile = file1 | (file2 << 8) | (file3 << 16) | (file4 << 24); // Convert little-endian to big-endian 4 byte int
					break;
			// WAVE (Bytes: 9-12)
				case 9: wave1 = ch;
					break;
				case 10: wave2 = ch;
					break;
				case 11: wave3 = ch;
					break;
				case 12: wave4 = ch;
					break;
			// Format Chunk (Bytes: 13-16)
				case 13: fmt1 = ch;
					break;
				case 14: fmt2 = ch;
					break;
				case 15: fmt3 = ch;
					break;
				case 16: fmt4 = ch;
					break;
			// Size of Format (Bytes: 17-20)
				case 17: format1 = ch;
					break;
				case 18: format2 = ch;
					break;
				case 19: format3 = ch;
					break;
				case 20: format4 = ch;
					SizeOfFormat = format1 | (format2 << 8) | (format3 << 16) | (format4 << 24); // Convert little-endian to big-endian
					break;
			// WAVE format (Bytes: 21-22)
				case 21: wave_format1 = ch;
					break;
				case 22: wave_format2 = ch;
					WAVEformat = wave_format1 | (wave_format2 << 8); // Convert little-endian to big-endian 2 byte int
					break;
			// MonoStereo (Bytes: 23-24)
				case 23: mono1 = ch;
					break;
				case 24: mono2 = ch;
					MonoStereo = mono1 | (mono2 << 8); // Convert little-endian to big-endian 2 byte int
					break;
			// SampleRate (Bytes: 25-28)
				case 25: sample1 = ch;
					break;
				case 26: sample2 = ch;
					break;
				case 27: sample3 = ch;
					break;
				case 28: sample4 = ch;
					SampleRate = sample1 | (sample2 << 8) | (sample3 << 16) | (sample4 << 24); // Convert little-endian to big-endian
					break;
			// BytesPerSec (Bytes: 29-32)
				case 29: bytes1 = ch;
					break;
				case 30: bytes2 = ch;
					break;
				case 31: bytes3 = ch;
					break;
				case 32: bytes4 = ch;
					BytesPerSec = bytes1 | (bytes2 << 8) | (bytes3 << 16) | (bytes4 << 24);  // Convert little-endian to big-endian
					break;
			// BlockAlign (Bytes: 33-34)
				case 33: block1 = ch;
					break;
				case 34: block2 = ch;
					BlockAlign = block1 | (block2 << 8); // Convert little-endian to big-endian 2 byte int
					break;
			// BitsPerSample (Bytes: 35-36)
				case 35: bits1 = ch;
					break;
				case 36: bits2 = ch;
					BitsPerSample = bits1 | (bits2 << 8); // Convert little-endian to big-endian 2 byte int
					break;
			// data (Bytes: 37-40)
				case 37: data1 = ch;
					break;
				case 38: data2 = ch;
					break;
				case 39: data3 = ch;
					break;
				case 40: data4 = ch;
					break;
			// SizeOfData (Bytes: 40-44)
				case 41: size1 = ch;
					break;
				case 42: size2 = ch;
					break;
				case 43: size3 = ch;
					break;
				case 44: size4 = ch;
					SizeOfData = size1 | (size2 << 8) | (size3 << 16) | (size4 << 24); // Convert little-endian to big-endian 4 byte int
					break;
			}
			if (nbytes == 44) // The rest of the bytes don't need to be stored into a variable
				break;
		}

		// Checking the requirements
		while (n != 0) {
			// Checking: 'RIFF'
			if (riff1 != 'R' || riff2 != 'I' || riff3 != 'F' || riff4 != 'F') {  // Checking the ASCII codes
				fprintf(stderr, "Error! RIFF not found.\n");
				break;
			}
			if (MODE != 1) {
				printchar(riff1, riff2, riff3, riff4);  // Transfer these (char) bytes to the new file, using putchar
			}
			// Checking: Size of File
			fprintf(stderr, "\nSize of file: %d\n", SizeOfFile);
			if (MODE == 2 || MODE == 3 || MODE == 6 || ((MODE == 4 || MODE == 5) && MonoStereo == 1)) {
				printint(file1, file2, file3, file4);  // Transfer these (int) bytes to the new file, using putchar
			}
			else if ((MODE == 4 || MODE == 5) && MonoStereo == 2) {
				newSizeOfFile = SizeOfFile - (SizeOfData / 2); // In general it is SizeOfFile = 36 + SizeOfData + SizeOfExtra
				calc(newSizeOfFile, 4); // Break newSizeOfFile into 4 bytes
			}
			// Checking: 'WAVE'
			if (wave1 != 'W' || wave2 != 'A' || wave3 != 'V' || wave4 != 'E'){ // Checking the ASCII codes
				fprintf(stderr, "Error! WAVE not found.\n");
				break;
			}
			if (MODE != 1) {
				printchar(wave1, wave2, wave3, wave4);
			}
			// Checking: Format Chunk ('fmt ')
			if (fmt1 != 'f' || fmt2 != 'm' || fmt3 != 't' || fmt4 != ' '){ // Checking the ASCII codes
				fprintf(stderr, "Error! fmt not found.\n");
				break;
			}
			if (MODE != 1) {
				printchar(fmt1, fmt2, fmt3, fmt4);
			}
			// Checking: Size of Format
			fprintf(stderr, "Size of format chunk: %d\n", SizeOfFormat);
			if (SizeOfFormat != 16){ // Requirement
				fprintf(stderr, "Error! Size of format chunk should be 16.\n");
				break;
			}
			if (MODE != 1) {
				printint(format1, format2, format3, format4);
			}
			// Checking: WAVE format
			fprintf(stderr, "WAVE type format: %d\n", WAVEformat);
			if (WAVEformat != 1) { // Requirement
				fprintf(stderr, "Error! WAVE type format should be 1.");
				break;
			}
			if (MODE != 1) {
				putchar(wave_format1);
				putchar(wave_format2);
			}
			// Checking: MonoStereo
			fprintf(stderr, "mono/stereo: %d\n", MonoStereo);
			if (MonoStereo != 1 && MonoStereo != 2) { // Requirement
				fprintf(stderr, "Error mono/stereo should be 1 or 2.\n");
				break;
			}
			if (MODE == 2 || MODE == 3 || MODE == 6 || ((MODE == 4 || MODE == 5) && MonoStereo == 1)) {
				putchar(mono1); // In these cases MonoStereo doesn't change
				putchar(mono2);
			}
			else if ((MODE == 4 || MODE == 5) && MonoStereo == 2) {
				calc(MonoStereo / 2, 2); // new_MonoStereo = 1
			}
			// Checking: SampleRate
			fprintf(stderr, "Sample rate: %d\n", SampleRate);
			if (MODE == 2){
				calc(SampleRate / 2, 4); // MODE_2: new_SampleRate=SampleRate / 2
			}
			else if (MODE == 3){
				calc(SampleRate * 2, 4); // MODE_3: new_SampleRate = SampleRate * 2
			}
			else if (MODE == 4 || MODE == 5 || MODE == 6) {
				printint(sample1, sample2, sample3, sample4); // MODE_4,5,6: SampleRate remains as it is
			}
			// Checking: BytesPerSec
			fprintf(stderr, "Bytes/sec: %d\n", BytesPerSec);
			if (MODE == 2 || ((MODE == 4 || MODE == 5) && MonoStereo == 2)) {
				calc(BytesPerSec / 2, 4); // new_BytesPerSec = BytesPerSec / 2
			}
			else if (MODE == 3) {
				calc(BytesPerSec * 2, 4); // MODE_3: new_BytesPerSec=BytesPerSec * 2
			}
			else if (MODE == 6 || ((MODE == 4 || MODE == 5) && MonoStereo == 1)) {
				printint(bytes1, bytes2, bytes3, bytes4); // BytesPerSec remains as it is
			}
			// Checking: BlockAlign
			fprintf(stderr, "Block alignment: %d\n", BlockAlign);
			if (BytesPerSec != (SampleRate * BlockAlign)) { // Requirement
				fprintf(stderr, "Error! bytes/sec should be sample rate x block alignment.\n");
				break;
			}
			if (MODE == 2 || MODE == 3 || MODE == 6 || ((MODE == 4 || MODE == 5) && MonoStereo == 1)) {
				putchar(block1); // BlockAlign doesn't change
				putchar(block2);
			}
			else if ((MODE == 4 || MODE == 5) && MonoStereo == 2) {
				calc(BlockAlign / 2, 2); // new_BlockAlign = BlockAlign / 2
			}
			// Checking: BitsPerSample
			fprintf(stderr, "Bits/sample: %d\n", BitsPerSample);
			if (BitsPerSample != 8 && BitsPerSample != 16) { // Requirement
				fprintf(stderr, "Error! bits/sample should be 8 or 16.\n");
				break;
			}
			if (BlockAlign != ((BitsPerSample / 8) * MonoStereo)) { // Requirement
				fprintf(stderr, "Error! Block alignment should be bits per sample / 8 x mono/stereo.\n");
				break;
			}
			if (MODE != 1) { // BitsPerSample doesn't change in any case
				putchar(bits1);
				putchar(bits2);
			}
			// Checking: 'data'
			if (data1 != 'd' || data2 != 'a' || data3 != 't' || data4 != 'a') { // Checking the ASCII codes
				fprintf(stderr, "Error! data not found.\n");
				break;
			}
			if (MODE != 1) {
				printchar(data1, data2, data3, data4);
			}
			// Checking: SizeOfData
			fprintf(stderr, "Size of data chunk: %d\n", SizeOfData);
			if (MODE == 2 || MODE == 3 || MODE == 6 || ((MODE == 4 || MODE == 5) && MonoStereo == 1)) {
				printint(size1, size2, size3, size4); // SizeOfData doesn't change
			}
			else if ((MODE == 4 || MODE == 5) && MonoStereo == 2) { // Transfer half of the bytes
				calc(SizeOfData / 2, 4); // new_SizeOfData=SizeOfData / 2
			}
			// Deal with the rest of the bytes
			while ((ch = getchar()) != EOF) {
				nbytes++;
				if (MODE == 2 || MODE == 3 || ((MODE == 4 || MODE == 5) && MonoStereo == 1)) {
					putchar(ch);  // The sound's data will be transfered as it is
				}
				else if ((MODE == 4 || MODE == 5) && MonoStereo == 2) {
					if (nbytes <= SizeOfData + 44) { // This only affects the bytes of sound's data
						if (BitsPerSample == 8) { // Each Sample is represented by one byte
							if (MODE == 4 && nbytes % 2 != 0) // For every two bytes, the first one has data for the left chanel (MODE_4)
								putchar(ch);
							if (MODE == 5 && nbytes % 2 == 0) // And the second byte has data for the right chanel (MODE_5)
								putchar(ch);
						}
						else if (BitsPerSample == 16) { // Each Sample is represented by two bytes
							if (MODE == 4 && i == 0) { // The first two bytes represent the first Sample for the left chanel (MODE_4)
								putchar(ch);
								if (nbytes % 2 == 0) // In MODE_4 print out the first two bytes and then ignore the next two, etc
									i = i + 2;
							}
							else
								i--;
							if (MODE == 5 && j == 0) { // The next two bytes (3rd, 4th) represent the first Sample of the right chanel
								putchar(ch); // MODE_5
								if (nbytes % 2 == 0) // In MODE_5 ignore the first two bytes and print out the next two, etc
									j = j + 2;
							}
							else
								j--;
						}
					}
					else // When the sound's data is printed, print out the rest of the bytes with other information
						putchar(ch);
				}
				else if (MODE == 6) {
					if (nbytes <= SizeOfData + 44) { // This only affects the sound's data
						if (BitsPerSample == 8) { // Each Sample is represented by one byte
							putchar(ch / 8);
						}
						else if (BitsPerSample == 16) { // Each Sample is represented by two bytes
							if (nbytes % 2 != 0) // First byte for the Sample
								d = ch;
							else { // If nbytes % 2 == 0, then ch=second_byte of the Sample
								Sample = d | (ch << 8); // Calculate the current Sample according to little-endian
								calcsample(Sample / 8);
							}
						}
					}
					else
						putchar(ch); // After the sound's data, print out the rest of the bytes which contain other information
				}
			}
			// Last checks
			if (nbytes < (SizeOfFile + 8)) {
				fprintf(stderr, "Error! Insufficient data.\n");
				break;
			}
			if (SizeOfFile != nbytes - 8) { // It must be SizeOfFile = TOTAL_BYTES - 8
				fprintf(stderr, "Error! Bad file size.\n");
				break;
			}
			n = 0;
		}
	}
	if (MODE == 7) {
		mysound(3, 44100, 2.0, 1500.0, 100.0, 30000.0);
	}
	return 0;
}

// Break a number into j bytes, so the number can be represented by these j bytes according to little-endian
void calc(int num, int j) {
	int byte, i;
	for (i = 1; i <= j; i++) {
		byte = num % 256;
		num = num / 256;
		putchar(byte); // Print out to the new file the bytes with the correct order, according to little-endian
	}
}

// Print out each char with the correct order using putchar
void printchar(char ch1, char ch2, char ch3, char ch4) {
	putchar(ch1);
	putchar(ch2);
	putchar(ch3);
	putchar(ch4);
}

// Print out each int with the correct order using putchar
void printint(int byte1, int byte2, int byte3, int byte4) {
	putchar(byte1);
	putchar(byte2);
	putchar(byte3);
	putchar(byte4);
}

// MODE_6,7: If BitsPerSample=16, break data samples into 2 bytes
void calcsample(short num) {
	short byte1, byte2, temp; // The Sample can be a positive or a negative number
	temp = num;
	byte1 = temp % 256;
	temp = temp / 256;
	byte2 = temp % 256;
	if (num < 0) {
		byte2--;
	}
	putchar(byte1); // Print out the new bytes
	putchar(byte2);
}

// Create a new file that follows the wav prototype
void mysound(int dur, int sr, double fm, double fc, double mi, double mv) {

	double t = 0.0;
	short ft;
	int SizeOfFile, MonoStereo = 1, BytesPerSec, BlockAlign, BitsPerSample = 16, SizeOfData = 0;
	BlockAlign = (BitsPerSample / 8) * MonoStereo;
	BytesPerSec = sr * BlockAlign;
	
	// Print out the bytes with the required information in the correct order
	printchar('R','I','F','F'); // Print out the ASCII codes
	for (t = 0.0; t <= dur; t = t + 1 / ((double)sr)){ // Count SizeOfFile
		SizeOfData = SizeOfData + 2; // For every value of the t variable, there are 2 bytes that represent one Sample of sound
	}
	SizeOfFile = SizeOfData + 36; // There is no extra information after the sound's data

	calc(SizeOfFile, 4);
	printchar('W', 'A', 'V', 'E'); // Print out the ASCII codes
	printchar('f', 'm', 't', ' '); // Print out the ASCII codes
	calc(16, 4); // SizeOfFormat=16, represented by 4 bytes
	calc(1, 2); // WAVEformat=1, represented by 2 bytes
	calc(1, 2); // MonoStereo=1, represented by 2 bytes
	calc(sr, 4); // SampleRate, represented by 4 bytes
	calc(BytesPerSec, 4); // BytesPerSec, 4 bytes
	calc(BlockAlign, 2); // BlockAlign, 2 bytes
	calc(BitsPerSample, 2); // BitsPerSample, 2 bytes
	printchar('d', 'a', 't', 'a'); // ASCII codes
	calc(SizeOfData, 4); // SizeOfData, 4 bytes

	for (t = 0.0; t <= 3.0; t = t + 1 / ((double)sr)) {
		ft = mv * sin(2 * M_PI * fc * t-mi * sin(2 * M_PI * fm * t)); // For every value of the t variable, ft is a data Sample
		calcsample(ft); // Print out the bytes for each Sample
	}
}
