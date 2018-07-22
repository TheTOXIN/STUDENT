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

        private Computer comp;
        private Info info;

        public Form1()
        {
            InitializeComponent();
            toolStripLabel1.Text = "SPT";
            this.comp = new Computer();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            toolStripComboBox1.Items.Add("EXP_1");
            toolStripComboBox1.Items.Add("EXP_2");
            toolStripComboBox1.Items.Add("EXP_3");
            toolStripComboBox1.Items.Add("EXP_4");
        }

        private void toolStripLabel1_Click(object sender, EventArgs e)
        {
            //CHANGE ALG
            if (this.alg == 1)
            {
                this.alg = 0;
                toolStripLabel1.Text = "SPT";
            }
            else
            {
                this.alg = 1;
                toolStripLabel1.Text = "RR";
            }
        }

        private void showConfig()
        {
            textBox1.Text = Config.R.ToString();
            textBox2.Text = Config.M.ToString();
            textBox3.Text = Config.Q.ToString();
            textBox4.Text = Config.C.ToString();
            textBox5.Text = Config.N.ToString();
            textBox6.Text = Config.L.ToString();
        }

        private void setConfig()
        {
            Config.R = int.Parse(textBox1.Text);
            Config.M = int.Parse(textBox2.Text);
            Config.Q = int.Parse(textBox3.Text);
            Config.C = int.Parse(textBox4.Text);
            Config.N = int.Parse(textBox5.Text);
            Config.L = int.Parse(textBox6.Text);
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            //COMPUTE
            setConfig();

            listBox1.Items.Clear();
            listBox2.Items.Clear();
            listBox3.Items.Clear();

            this.comp.dflt();

            Info info;

            if (alg == 0)
            {
                info = comp.computeSPT();
            }
            else
            {
                info = comp.computeRR();
            }

            MyView.getCPUs(listBox1, comp.CPUs);
            MyView.getTasks(listBox2, comp.tasks);
            MyView.getData(listBox3, info);
        }

        public void showQueue()
        {
            this.comp.update();
            this.comp.init();

            if (checkBox1.Checked)
                comp.tasks.Sort();

            Task[] ar = comp.tasks.ToArray();

            String res = "";
            foreach (Task t in ar)
                res += t.tmp + " -> ";

            richTextBox1.Text = res + '\n';
        }

        private void label7_Click(object sender, EventArgs e)
        {
            showQueue();
        }

        private void label11_Click(object sender, EventArgs e)
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
        }

        private void label1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("вероятность короткой задачи");
        }

        private void label2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("время максимальной задачи");
        }

        private void label3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("квант за 1 такт");
        }

        private void label4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("кол-во задач");
        }

        private void label5_Click(object sender, EventArgs e)
        {
            MessageBox.Show("кол-во процессов");
        }

        private void label6_Click(object sender, EventArgs e)
        {
            MessageBox.Show("время для задачи");
        }
    }
}
