
#include "neural_cup.h"
using namespace tensorflow;
using namespace std;

Session* TF_neural::session;
GraphDef TF_neural::graph_def;
Status TF_neural::status;
std::vector<std::pair<string, tensorflow::Tensor>> TF_neural::inputs;
std::vector<tensorflow::Tensor> TF_neural::outputs;
vector<Tensor>::iterator TF_neural::it;

int TF_neural::Create(){
	TF_neural::status = NewSession(SessionOptions(), &(TF_neural::session));
  if (!status.ok()) {
    std::cout << status.ToString() << "\n";
    return 0;
	}
	TF_neural::status = ReadBinaryProto(Env::Default(), "models/rec_SIGMASIGMA.pb", &(TF_neural::graph_def));
  if (!status.ok()) {
    std::cout << status.ToString() << "\n";
    return 0;
	}
	TF_neural::status = session->Create(TF_neural::graph_def);
  if (!status.ok()) {
    std::cout << status.ToString() << "\n";
    return 0;
  }
	
	Tensor checkpoint_filepath(DT_STRING, TensorShape());
	checkpoint_filepath.scalar<std::string>()() = "models/rec_SIGMASIGMA";
  TF_neural::session->Run( {{ "save/Const", checkpoint_filepath },}, 
                       {}, {"save/restore_all"}, &(TF_neural::outputs));
	return 1;
}
int TF_neural::Destroy(){
	TF_neural::session->Close();
}
bool TF_neural::neural_cup(float readinput[]) {

	
	Tensor x(DT_FLOAT, TensorShape({1,12}));
  for(int s=0;s<12;s++)
  {
    x.matrix<float>()(0,s) = *(readinput + s);
  }

	TF_neural::inputs = {{ "inputx", x },};

  TF_neural::session->Run(inputs, {"softmax_linear/logits"}, {}, &(TF_neural::outputs));

  it = TF_neural::outputs.begin();

  auto items = it->shaped<float, 2>({1, 2});

  if (items(0,0)>items(0,1))
  {
    return 0;
  }
  else
  {
    return 1;
  }

}
