#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    QString line = ui->inputBrowser->toPlainText();
    ui->outputBrowser->clear();

    //Do this in one line because append adds an endl by default reee.
    QString all;

    //Now we loop through the input browser.
    for (size_t i = 0; i < line.size(); ++i){
        if (line[i] == '\n'){
            all += "    ";
            continue;
        }

        std::string stdline = line.toStdString();
        switch(stdline[i]){
        /*case '-':
            all += ":dash:";
            break;
            */
        case ' ':
            all += "  ";
            break;
        case '?':
            all += ":grey_question:";
            break;
        case '!':
            all += ":grey_exclamation:";
            break;
        case '"':
            all += ":comet:";
            break;
        case ',':
            all += ":crescent_moon:";
            break;
        case '0':
            all += ":zero:";
            break;
        case '1':
            all += ":one:";
            break;
        case '2':
            all += ":two:";
            break;
        case '3':
            all += ":three:";
            break;
        case '4':
            all += ":four:";
            break;
        case '5':
            all += ":five:";
            break;
        case '6':
            all += ":six:";
            break;
        case '7':
            all += ":seven:";
            break;
        case '8':
            all += ":eight:";
            break;
        case '9':
            all += ":nine:";
            break;

        case '+':
            all += ":heavy_plus_sign:";
            break;
        case '-':
            all += ":heavy_minus_sign:";
            break;
        case '$':
            all += ":heavy_dollar_sign:";
            break;
        case '.':
            all += ":white_small_square:";
            break;
        case '*':
            all += ":eight_pointed_black_star:";
            break;




        default:
            if (line[i].isLetter()){
                all += QString(":regional_indicator_") + line[i].toLower() + ":";
            }
            break;
        }
        all += " ";
    }

    ui->outputBrowser->append(all);
    ui->numCharsLabel->setText("Number of chars (Discord Limit - 2000): " + QString::number((int)all.size()));

}
