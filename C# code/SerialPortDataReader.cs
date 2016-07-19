using System;
using System.Collections.Generic;
using System.Text;
using System.IO.Ports;
using System.Configuration;
using System.ComponentModel;
using System.Text.RegularExpressions;
using System.Threading;

namespace An_Assistive_Body_Sensor_Network
{
    public delegate void DataDelegate<T>(T aData);
    public partial class SerialPortDataReader
    {
        public static event DataDelegate<string> OnDataReceived;
        static SerialPort mySerialPort;
        static BackgroundWorker myBackgroundWorker = new BackgroundWorker();

        private static string myMainData;
        public static string MainData
        {
            get { return myMainData; }
            set { myMainData = value; }
        }


        public static SerialPort SerialPort
        {
            get { return mySerialPort; }
        }

        static SerialPortDataReader()
        {
            AppSettingsReader aAppSettingsReader = new AppSettingsReader();
            string aPortNumber = aAppSettingsReader.GetValue("Port", typeof(string)).ToString();
            int aBaudRate = int.Parse(aAppSettingsReader.GetValue("BaudRate", typeof(int)).ToString());
            Parity aParity = (Parity)Enum.Parse(typeof(Parity), aAppSettingsReader.GetValue("Parity", typeof(string)).ToString());
            int aDataBits = int.Parse(aAppSettingsReader.GetValue("DataBits", typeof(int)).ToString());
            mySerialPort = new SerialPort(aPortNumber, aBaudRate, aParity, aDataBits, StopBits.One);
            mySerialPort.DiscardNull = true;
            mySerialPort.ReadTimeout = 1000;
            mySerialPort.Open();

            myBackgroundWorker.WorkerSupportsCancellation = true;
            myBackgroundWorker.WorkerReportsProgress = true;
            myBackgroundWorker.ProgressChanged += new ProgressChangedEventHandler(myBackgroundWorker_ProgressChanged);
            myBackgroundWorker.RunWorkerCompleted += new RunWorkerCompletedEventHandler(myBackgroundWorker_RunWorkerCompleted);
            myBackgroundWorker.DoWork += new DoWorkEventHandler(myBackgroundWorker_DoWork);
            myBackgroundWorker.RunWorkerAsync();
            // mySerialPort.DataReceived += new SerialDataReceivedEventHandler(mySerialPort_DataReceived);
        }

        static void myBackgroundWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            while (true)
            {
                try
                {
                    if (mySerialPort.IsOpen)
                    {
                        Thread.Sleep(500);
                        string aData = mySerialPort.ReadExisting();
                        if (!string.IsNullOrEmpty(aData))
                        {
                            aData = Regex.Replace(aData, "[\r\n]", string.Empty);
                            myBackgroundWorker.ReportProgress(1, aData);
                        }
                    }
                    else
                    {
                        return;
                    }
                }
                catch (InvalidOperationException IO)
                {

                }
                catch (TimeoutException tio)
                {

                }
            }
        }


        public static void SendDataToPort(string theMessage)
        {
            if (mySerialPort != null && mySerialPort.IsOpen)
            {
                mySerialPort.Write(theMessage);
            }
        }

        static void myBackgroundWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {

        }

        static void myBackgroundWorker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            if (OnDataReceived != null && e.UserState != null)
            {
                OnDataReceived(e.UserState.ToString());
            }
        }

        static void mySerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {

            if (e.EventType == SerialData.Chars)
            {

            }
        }

        public static void Close()
        {
            mySerialPort.Close();
        }
    }
}
