using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using SpeechLib;

namespace An_Assistive_Body_Sensor_Network
{    
    public partial class Frm_Main : Form
    {
        private SpVoice voice;
        public Frm_Main()
        {
            InitializeComponent();
            voice = new SpVoice();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Frm_Main_Load(object sender, EventArgs e)
        {           
            Use_Notify();
           SerialPortDataReader.OnDataReceived += new DataDelegate<string>(SerialPortDataReader_OnDataReceived);
            voice.Speak("Hi Welcome to An Assistive Body Sensor Network Glove for Speech and Hearing Impaired Disabilities", SpeechVoiceSpeakFlags.SVSFDefault);
        }
        private void Use_Notify()
        {
            nfyIconBodySensor.ContextMenuStrip = contextMenuStrip1;
            nfyIconBodySensor.BalloonTipText = "Our Project is Developed only for Academic Project";
            nfyIconBodySensor.BalloonTipTitle = "Glove for Speech & Hearing Disabilities";
            nfyIconBodySensor.ShowBalloonTip(1);
        }
        
        void SerialPortDataReader_OnDataReceived(string aData)
        {
            if (aData.Length == 4)
            {
                try
                {
                    string[] dat = aData.Insert(3, "$").Split('$');
                    string Temp = dat[0];
                    string Stats = dat[1];


                    ShowThis();
                    if (timer1.Enabled)
                        StopTImer();
                    timer1.Enabled = true;
                    timer1.Start();
                    if (aData.Length >= 3)
                    {

                        lblTemperature.Text = Temp.ToString();
                        double tem = Convert.ToDouble(lblTemperature.Text.ToString());
                        if (tem >=20)
                        {
                            System.Diagnostics.Process.Start(@"C:\1.mp3");
                        }
                    }
                    switch (Stats)
                    {

                        case "1":
                            voice.Speak("i need a glass of water", SpeechVoiceSpeakFlags.SVSFDefault);
                            lblStatus.Text = "I need a glass of water!";
                            Bitmap bmp1 = new Bitmap(@"C:\BSN Images\1.jpg");
                            pictureBox1.Image = bmp1;
                            break;
                        case "2":
                            voice.Speak(" iam hungry i need food", SpeechVoiceSpeakFlags.SVSFDefault);
                            lblStatus.Text = "iam hungry i need food";
                            Bitmap bmp2 = new Bitmap(@"C:\BSN Images\2.jpg");
                            pictureBox1.Image = bmp2;
                            break;
                        case "3":
                            voice.Speak("good work congrats", SpeechVoiceSpeakFlags.SVSFDefault);
                            lblStatus.Text = "good work congrats";
                            Bitmap bmp3 = new Bitmap(@"C:\BSN Images\3.jpg");
                            pictureBox1.Image = bmp3;
                            break;
                        case "4":
                            voice.Speak("i need help urgently", SpeechVoiceSpeakFlags.SVSFDefault);
                            lblStatus.Text = "I need help urgently";
                            Bitmap bmp4 = new Bitmap(@"C:\BSN Images\4.jpg");
                            pictureBox1.Image = bmp4;
                            break;
                        case "5":

                            voice.Speak("iam getting sleep", SpeechVoiceSpeakFlags.SVSFDefault);
                            lblStatus.Text = "iam getting sleep";
                            Bitmap bmp5 = new Bitmap(@"C:\BSN Images\5.jpg");
                            pictureBox1.Image = bmp5;
                            break;
                        case "6":
                            voice.Speak("i have a very bad head ache", SpeechVoiceSpeakFlags.SVSFDefault);
                            lblStatus.Text = "i have a very bad head ache";
                            Bitmap bmp6 = new Bitmap(@"C:\BSN Images\6.jpg");
                            pictureBox1.Image = bmp6;
                            break;
                        case "7":
                            voice.Speak("i need to use the wash room now", SpeechVoiceSpeakFlags.SVSFDefault);
                            lblStatus.Text = "i need to use the wash room now";
                            Bitmap bmp7 = new Bitmap(@"C:\BSN Images\7.jpg");
                            pictureBox1.Image = bmp7;
                            break;
                            
                        case "8":
                            //lblDestination.Text = "Bijapur 5th Block";
                            //Bitmap bmp8 = new Bitmap(@"C:\EImage\D5.png");
                            //pbDestination.Image = bmp8;
                            break;
                    }
                }
                catch (SystemException ex)
                {
                    MessageBox.Show(ex.ToString());
                }
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Hide();
            StopTImer();
        }
        private void StopTImer()
        {
            timer1.Enabled = false;
            timer1.Stop();
        }

        private void nfyIconBodySensor_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            ShowThis();
        }
        private void ShowThis()
        {
            this.WindowState = FormWindowState.Normal;
            Show();
        }

        private void Frm_Main_Resize(object sender, EventArgs e)
        {
            if (FormWindowState.Minimized == WindowState)
                Hide();
        }

        private void showToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ShowThis();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void HelpStrip_Click(object sender, EventArgs e)
        {
            Frm_Help frh = new Frm_Help();
            frh.Show();
        }

        private void lblStatus_Click(object sender, EventArgs e)
        {

        }

        private void panelMain_Paint(object sender, PaintEventArgs e)
        {

        }       
    }
}