#include "niveaux.h"

Niveaux::Niveaux()
{
    setFixedSize(500, 300);
    QPalette fond;
    fond.setBrush(backgroundRole(),QBrush(QColor(131, 156, 114)));
    setPalette(fond);

    menuComplet = new QVBoxLayout;
    menu = new QGridLayout;

    jetia = new QFormLayout;
    joueur = new QSpinBox;
    ia = new QSpinBox;
    joueur->setMinimum(1);
    joueur->setMaximum(4);
    ia->setMinimum(0);
    ia->setMaximum(4);
    jetia->addRow("Nombre de joueur : ", joueur);
    jetia->addRow("Nombre d'IA : ", ia);

    menuComplet->addLayout(jetia);

    niv1 = new QPushButton("Niveau 1");
    menu->addWidget(niv1, 0, 0);
    connect(niv1, SIGNAL(clicked()), this, SLOT(niveau1()));
    niv2 = new QPushButton("Niveau 2");
    menu->addWidget(niv2, 0, 1);
    connect(niv2, SIGNAL(clicked()), this, SLOT(niveau2()));
    niv3 = new QPushButton("Niveau 3");
    menu->addWidget(niv3, 0, 2);
    connect(niv3, SIGNAL(clicked()), this, SLOT(niveau3()));
    niv4 = new QPushButton("Niveau 4");
    menu->addWidget(niv4, 0, 3);
    connect(niv4, SIGNAL(clicked()), this, SLOT(niveau4()));
    niv5 = new QPushButton("Niveau 5");
    menu->addWidget(niv5, 1, 0);
    connect(niv5, SIGNAL(clicked()), this, SLOT(niveau5()));
    niv6 = new QPushButton("Niveau 6");
    menu->addWidget(niv6, 1, 1);
    connect(niv6, SIGNAL(clicked()), this, SLOT(niveau6()));
    niv7 = new QPushButton("Niveau 7");
    menu->addWidget(niv7, 1, 2);
    connect(niv7, SIGNAL(clicked()), this, SLOT(niveau7()));
    niv8 = new QPushButton("Niveau 8");
    menu->addWidget(niv8, 1, 3);
    connect(niv8, SIGNAL(clicked()), this, SLOT(niveau8()));
    niv9 = new QPushButton("Niveau 9");
    menu->addWidget(niv9, 2, 0);
    connect(niv9, SIGNAL(clicked()), this, SLOT(niveau9()));
    niv10 = new QPushButton("Niveau 10");
    menu->addWidget(niv10, 2, 1);
    connect(niv10, SIGNAL(clicked()), this, SLOT(niveau10()));
    niv11 = new QPushButton("Niveau 11");
    menu->addWidget(niv11, 2, 2);
    connect(niv11, SIGNAL(clicked()), this, SLOT(niveau11()));
    niv12 = new QPushButton("Niveau 12");
    menu->addWidget(niv12, 2, 3);
    connect(niv12, SIGNAL(clicked()), this, SLOT(niveau12()));
    niv13 = new QPushButton("Niveau 13");
    menu->addWidget(niv13, 3, 0);
    connect(niv13, SIGNAL(clicked()), this, SLOT(niveau13()));
    niv14 = new QPushButton("Niveau 14");
    menu->addWidget(niv14, 3, 1);
    connect(niv14, SIGNAL(clicked()), this, SLOT(niveau14()));
    niv15 = new QPushButton("Niveau 15");
    menu->addWidget(niv15, 3, 2);
    connect(niv15, SIGNAL(clicked()), this, SLOT(niveau15()));
    niv16 = new QPushButton("Niveau 16");
    menu->addWidget(niv16, 3, 3);
    connect(niv16, SIGNAL(clicked()), this, SLOT(niveau16()));
    niv17 = new QPushButton("Niveau 17");
    menu->addWidget(niv17, 4, 1);
    connect(niv17, SIGNAL(clicked()), this, SLOT(niveau17()));
    niv18 = new QPushButton("Niveau 18");
    menu->addWidget(niv18, 4, 2);
    connect(niv18, SIGNAL(clicked()), this, SLOT(niveau18()));
    nivAleatoire = new QPushButton("Niveau Aléatoire");
    menu->addWidget(nivAleatoire, 5, 1, 1, 2);
    connect(nivAleatoire, SIGNAL(clicked()), this, SLOT(nivAlea()));

    menuComplet->addLayout(menu);
    setLayout(menuComplet);
}

void Niveaux::niveau1()
{
    ToutEnUn *jeu = new ToutEnUn(1345, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau2()
{
    ToutEnUn *jeu = new ToutEnUn(5641, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau3()
{
    ToutEnUn *jeu = new ToutEnUn(4698, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau4()
{
    ToutEnUn *jeu = new ToutEnUn(1974, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau5()
{
    ToutEnUn *jeu = new ToutEnUn(8979, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau6()
{
    ToutEnUn *jeu = new ToutEnUn(9412, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau7()
{
    ToutEnUn *jeu = new ToutEnUn(4894, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau8()
{
    ToutEnUn *jeu = new ToutEnUn(5808, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau9()
{
    ToutEnUn *jeu = new ToutEnUn(2908, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau10()
{
    ToutEnUn *jeu = new ToutEnUn(2209, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau11()
{
    ToutEnUn *jeu = new ToutEnUn(1111, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau12()
{
    ToutEnUn *jeu = new ToutEnUn(8975, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau13()
{
    ToutEnUn *jeu = new ToutEnUn(9531, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau14()
{
    ToutEnUn *jeu = new ToutEnUn(1798, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau15()
{
    ToutEnUn *jeu = new ToutEnUn(1515, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau16()
{
    ToutEnUn *jeu = new ToutEnUn(4989, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau17()
{
    ToutEnUn *jeu = new ToutEnUn(7897, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::niveau18()
{
    ToutEnUn *jeu = new ToutEnUn(0070, joueur->value(), ia->value());
    jeu->show();
    this->close();
}

void Niveaux::nivAlea()
{
    ToutEnUn *jeu = new ToutEnUn(-1, joueur->value(), ia->value());
    jeu->show();
    this->close();
}
