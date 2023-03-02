#include <iostream>
#include <string>
#include <cstring>
const int k_iValidCodeChecksum = 5;

const char k_cAuthenticatorCodeCharacter1 = 'E';
const char k_cAuthenticatorCodeCharacter2 = 'C';
const char k_cAuthenticatorCodeCharacter3 = 'A';
std::string m_authenticatorCode = "";

char m_codechar1;
char m_codechar2;
char m_codechar3;
std::string m_inputCode = "";

int main() {
    //Entering & Displaying the Codes
    std::cout << "Enter the first character of the message code: " << std::endl;
    std::cin >> m_codechar1;
    std::cout << "Enter the second character of the message code: " << std::endl;
    std::cin >> m_codechar2;
    std::cout << "Enter the third character of the message code: " << std::endl;
    std::cin >> m_codechar3;


    m_authenticatorCode += k_cAuthenticatorCodeCharacter1;
    m_authenticatorCode += k_cAuthenticatorCodeCharacter2;
    m_authenticatorCode += k_cAuthenticatorCodeCharacter3;
    std::cout << "Authenticator code: " << m_authenticatorCode << std::endl;


    m_inputCode += m_codechar1;
    m_inputCode += m_codechar2;
    m_inputCode += m_codechar3;
    std::cout << "Message code: " << m_inputCode << std::endl;


    //Report authenticity using character comparison
    if ((k_cAuthenticatorCodeCharacter1 == m_codechar1) && (k_cAuthenticatorCodeCharacter2 == m_codechar2) &&
        (k_cAuthenticatorCodeCharacter3 == m_codechar3)){
        std::cout << "Message is authentic." << std::endl;
    }
    else{
        std::cout << "Message is invalid. :(" << std::endl;
    }


    //Report authenticity using string comparison
    int result = m_authenticatorCode.compare(m_inputCode);
    if (result == 0){
        std::cout << "Concurrence- Message is Authentic." << std::endl;
    }
    else{
        std::cout << "Concurrence- Message is Invalid." << std::endl;
    }


    //Calculate & Print Checksum
    int m_checksum = (int(m_codechar1) + int(m_codechar2) + int(m_codechar3)) % 7;
    if (k_iValidCodeChecksum == m_checksum){
        std::cout << "Message code CheckSum is valid: 5" << std::endl;
    }
    else{
        std::cout << "Message code CheckSum is invalid: " << m_checksum << "; Expected: 5" << std::endl;
    }


    //Print ASCII Values
    std::cout << "ASCII Values of Message Code Chars: " << int(m_codechar1) << "," << int(m_codechar2) << "," <<
                int(m_codechar3) << "." << std::endl;
    //Print sum of ASCII Vals
    std::cout << "Sum of ASCII Values for Message Code Chars: " << (int(m_codechar1) + int(m_codechar2) + int(m_codechar3))
                << "." << std::endl;


    //Print out message pairs that do NOT match
    if (k_cAuthenticatorCodeCharacter1 != m_codechar1){
        std::cout << "First characters do not match. Message: " << m_codechar1 << "; Authenticator: " <<
                    k_cAuthenticatorCodeCharacter1 << std::endl;
    }
    if (k_cAuthenticatorCodeCharacter2 != m_codechar2){
        std::cout << "Second characters do not match. Message: " << m_codechar2 << "; Authenticator: " <<
                  k_cAuthenticatorCodeCharacter2 << std::endl;
    }
    if (k_cAuthenticatorCodeCharacter3 != m_codechar3){
        std::cout << "Third characters do not match. Message: " << m_codechar3 << "; Authenticator: " <<
                  k_cAuthenticatorCodeCharacter3 << std::endl;
    }

    //Print out lexicographical relationship
    if (m_inputCode > m_authenticatorCode){
        std::cout << "Message code (" << m_inputCode << ") is lexicographically greater than Authenticator code ("
                  << m_authenticatorCode << ")" << std::endl;
    }
    else if (m_inputCode < m_authenticatorCode){
        std::cout << "Message code (" << m_inputCode << ") is lexicographically less than Authenticator code ("
                  << m_authenticatorCode << ")" << std::endl;
    }

    return 0;
}
