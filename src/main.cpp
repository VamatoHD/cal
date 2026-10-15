#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BebidaType {
public:
    string nome;
    float teor_alcool;

    BebidaType(string nome, float teor_alcool) {
        this->nome = nome;
        this->teor_alcool = teor_alcool;
    }

    BebidaType() {
        this->nome = "";
        this->teor_alcool = 0.0;
    }

    string Resumo() {
        return nome + " - " + to_string(teor_alcool) + "%";
    }

    bool operator==(const BebidaType &outro) const {
        return this->nome == outro.nome && this->teor_alcool == outro.teor_alcool;
    }
};

class Bebida {
public:
    BebidaType tipo;
    float volume; // mls

    Bebida(BebidaType tipo, float volume) : tipo(tipo), volume(volume) {}

     float to_mg() const {
        return volume * this->tipo.teor_alcool * 0.01 * 0.789;
    }
};

class Pessoa {
public:
    string nome;
    vector<Bebida> bebidas;

    Pessoa(string nome) {
        this->nome = nome;
        this->bebidas = vector<Bebida>();
    }

    void Adicionar_bebida(const BebidaType &tipo, float volume) {
        for (size_t i = 0; i < bebidas.size(); i++) {
            if (bebidas[i].tipo == tipo) {
                bebidas[i].volume += volume;
                return;
            }
        }

        bebidas.push_back(Bebida(tipo, volume));
        return;
    }

    float Calcular_alcool_mg() {
        float res = 0.0;
        for (size_t i = 0; i < bebidas.size(); i++) {
            res += bebidas[i].to_mg();
        }
        return res;
    }

    void Resumo() {
        std::cout << "Resumo de " << nome << endl;
        for (size_t i = 0; i < bebidas.size(); i++) {
            const Bebida &bebida = bebidas[i];
            std::cout << "  - " << bebida.tipo.nome << " (" << bebida.tipo.teor_alcool << "%)" << endl;
            std::cout << "    " << bebida.volume << "ml = " << bebida.to_mg()  << "mg alcool" << endl;
        }
    }
};

int main() {
    vector<BebidaType> tipos = vector<BebidaType>();

    tipos.push_back(BebidaType("Cerveja", 5.0));
    tipos.push_back(BebidaType("Vinho", 12.0));
    tipos.push_back(BebidaType("Vodka", 40.0));
    tipos.push_back(BebidaType("Absinto", 65.0));

    Pessoa ele = Pessoa("Seba");

    ele.Adicionar_bebida(tipos[0], 1000.0);
    ele.Adicionar_bebida(tipos[2], 25.0);
    ele.Adicionar_bebida(tipos[0], 1000.0);

    ele.Resumo();

    return 0;
}
