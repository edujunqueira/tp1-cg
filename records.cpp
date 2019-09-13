#include "records.h"

records::records()
{
    fileName = "records.txt";
    recordName = "";
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
    if(key == 27){ // tecla esc
        recordName = "";
        return true;
    }

    recordName += key;

    if(recordName.length() >= 5){
        this->processWin();
        return true;
    }

    return false;
}
