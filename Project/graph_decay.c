void graph_decay()
{
    TCanvas *c = new TCanvas("c","Decay",0,0,800,400);

    TGraph *dt = new TGraph("decay2.dat");
        
    dt->SetTitle("Decay; Time ; Number of atoms ");
    
    dt->SetMarkerColor(36);
    dt->SetMarkerSize(0.5);
    dt->SetMarkerStyle(5);
    
    c->Draw();    
    dt->Draw();

    
    return c;
};
