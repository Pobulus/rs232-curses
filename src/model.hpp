class RS232 {
public:
//Otwiera połączenie, zwraca true jeśli udane
bool openConnection(
	const char *port,		//wybór portu np. "\\\\.\\COM1"
	const unsigned int baudRate,	//szybkość
	const bool sevenDataBits,	//true - 7 bitów danych, false - 8 bitów danych
	const char controlEON,		//"E", "O", "N" - parzystość
	const bool oneStopBit,		//true - 1 bit stopu, false - 2 bity stopu
	const char flowControl,		//kontrola przepływu: 0 - brak, 1 - handshake, 2 - programowa
	const char terminatorOption,	//opcja terminatora: 0 - brak, 1 - standardowy, 2 - własny
	const char *terminator = "");	//terminator: brak - pusty/ignorowany, standardowy - "CR", "LF", "CRLF", własny - brane pod uwagę pierwsze 2 znaki

//Zwraca true, jeżeli połączono
bool isConnected();

//Zamyka połączenie
void closeConnection();

//Nadawanie, zwraca true jeśli udane
bool write(const char *text);	//ciąg znaków do nadania na port

//Odbiór, zwraca true jeśli udane
bool read(char *text);	//ciąg znaków odczytany z portu

//Wykonuje operację ping z pomiarem czasu
void ping(
    char *pingResults, 		//output dla ping'a
	const int packagesNumber = 5,	//liczba pakietów do wysłania
	const unsigned int timeout = 10);//timeout dla pojedynczego pakietu w ms
};
