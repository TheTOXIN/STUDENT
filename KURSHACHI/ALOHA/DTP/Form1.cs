using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DTP
{
    public partial class Form1 : Form
    {
        private int exp = 0;
        private int alg = 0;

        private Random r = new Random();
        private Algorithm comp;

        public Form1()
        {
            comp = new Algorithm();
            InitializeComponent();
            toolStripLabel1.Text = "АСИНХРОН";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            toolStripComboBox1.Items.Add("ОПЫТ_1");
            toolStripComboBox1.Items.Add("ОПЫТ_2");
            toolStripComboBox1.Items.Add("ОПЫТ_3");
            toolStripComboBox1.Items.Add("ОПЫТ_4");

            toolStripComboBox2.Items.Add("10");
            toolStripComboBox2.Items.Add("100");
            toolStripComboBox2.Items.Add("1000");
            toolStripComboBox2.Items.Add("10000");
        }

        private void toolStripLabel1_Click(object sender, EventArgs e)
        {
            //CHANGE ALG
            if (this.alg == 1)
            {
                this.alg = 0;
                toolStripLabel1.Text = "АСИНХРОН";
            }
            else
            {
                this.alg = 1;
                toolStripLabel1.Text = "СИНХРОН";
            }
        }

        private void showConfig()
        {
            textBox1.Text = Config.G.ToString();
            textBox2.Text = Config.I.ToString();
            textBox3.Text = Config.U.ToString();
        }

        private void setConfig()
        {
            Config.G = double.Parse(textBox1.Text);
            Config.I = int.Parse(textBox2.Text);
            Config.U = int.Parse(textBox3.Text);
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            //COMPUTE
            settings();
            setConfig();
            clear();

            double p = 0;

            if (alg == 0)
                p = comp.aloha();
            else
                p = comp.clearAloha();

            Info info = comp.compute(p);

            MyView.getTasks(listBox2, comp.packets);
            MyView.getData(listBox3, info);
        }

        private void settings()
        {
            //CHANGE EXP
            this.exp = toolStripComboBox1.SelectedIndex;
            switch (this.exp)
            {
                case 0: Config.setExp1(); break;
                case 1: Config.setExp2(); break;
                case 2: Config.setExp3(); break;
                case 3: Config.setExp4(); break;
            }

            showConfig();
            Config.N = int.Parse((String)toolStripComboBox2.SelectedItem);
        }

        public void clear()
        {
            comp.packets.Clear();
            listBox2.Items.Clear();
            listBox3.Items.Clear();
        }
    }
}
