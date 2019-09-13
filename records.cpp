#include "records.h"

records::records()
{
    fileName = "records.txt";
    recordName = "";
}

void records::desenhaPopUp(int scorer)
{
    // tela preta
    glColor4f(0.0, 0.0, 0.0, 0.5);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(10, 10, 0);
        glVertex3f(190, 10, 0);
        glVertex3f(190, 90,  0);
        glVertex3f(10, 90, 0);
    glEnd();
    if(scorer == PLAYER_ONE)
        escreveFrase("player one wins!", 100, 20, 4, 4);
    else if(scorer == PLAYER_TWO)
        escreveFrase("player two wins!", 100, 20, 4, 4);
    escreveFrase("escreva seu nome para entrar nos recordes", 100, 40, 2, 2);
    escreveFrase("aperte enter para confirmar ou esc para sair", 100, 50, 2, 2);
    escreveFrase(recordName, 100, 70, 4, 4);
    // nome atual escrevendo
}

void records::teste()
{


}

void records::processWin()
{
    bool isInRecords = false;
    std::string str;
    readFile.open(fileName);
    while(getline(readFile, str)) // lê os recordes
    {
        record holder( str.substr(0, str.find(":")), std::stoi(str.substr(str.find(":") + 2)));
        holders.push_back(holder);
        // salva todos em um vector
    }

    for(std::vector<record>::iterator it = holders.begin(); it != holders.end(); ++it){
        if(it->getName() == recordName){
            it->addScore();
            isInRecords = true;
        }
    }
    // itera pelo vector, procurando se algum nome é igual ao que vai ser guardado agora
    // se for, adciona um ponto de score pra ele

    if(!isInRecords){
        record newHolder(recordName, 1);
        holders.push_back(newHolder);
    }
    // se já não estiver nos records, cria um novo

    std::sort(holders.begin(), holders.end(),
        [](const record & a, const record & b) -> bool
          { return a.getScore() > b.getScore(); });
    // com o novo recorde no vector, ordena por score

    readFile.close();
    // fecha o arquivo para leitura

    writeFile.open(fileName, std::ios::trunc);
    // abre o arquivo para escrita com sobrescrita
    for(std::vector<record>::iterator it = holders.begin(); it != holders.end(); ++it){
        writeFile << it->getRecord() + "\n";
    }
    // reescreve os records no arquivo
    writeFile.close();
    holders.clear();
    // limpa o vector
    recordName = "";
    // reseta o nome para o próximo recorde
}

bool records::processName(unsigned char key) // return true = acabou, false = continua
{
     // se apertar a tecla esc, acaba sem processar o recorde
    if(key == 27){
        recordName = "";
        return true;
    }

    // se der enter, e tiver o minimo de 3 caracteres, processa o recorde
    if(key == 13 && recordName.length() >= 3){
        this->processWin();
        return true;
    }

    // se der backspace, e tiver pelo menos 1 caracter, apaga 1 caracter
    if(key == 8 && recordName.length() >= 1){
        recordName.pop_back();
        return false;
    }

    // se estiver dentro das possibilidades de digitação, e não for maior que 8 caracteres
    if( recordName.length() < 8 && ((key >= 'a' && key <= 'z') || (key >= '0' && key <= '9')) )
        recordName += key;

    return false;
}
