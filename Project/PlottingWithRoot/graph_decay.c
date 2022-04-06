//Ejecutar: "root graph_decay.c"

void graph_decay()
{
    TCanvas *c = new TCanvas("c","Decay",0,0,800,400);

    TGraph *dt = new TGraph("decay.dat");
        
    dt->SetTitle("Decay; Time ; Number of atoms ");
    
    dt->SetMarkerColor(36);
    dt->SetMarkerSize(0.5);
    dt->SetMarkerStyle(5);
    
    TF1* fit = new TF1("fit", "[N]*exp([decay]*x)");
    dt->Fit("fit");
    
    c->Draw();    
    dt->Draw();

    
    return c;
};
