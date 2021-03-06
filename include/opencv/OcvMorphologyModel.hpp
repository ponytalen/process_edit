#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>
#include <iostream>
#include <nodes/DataModelRegistry>
#include <nodes/NodeDataModel>
#include "OcvBaseNode.hpp"
#include "OcvData.hpp"

class OcvMophologyModel : public OcvBaseNode
{
  Q_OBJECT
 public:
  OcvMophologyModel();
  ~OcvMophologyModel(){};

  QString caption() const override { return QString("Mophology"); }
  QString name() const override { return QString("OcvMophologyModel"); }
  virtual QString modelName() const { return QString("CvtMophology"); }
  void process() override;
  std::shared_ptr<NodeData> outData(PortIndex idx) override;

 private:
  void Mophology(cv::Mat& src, cv::Mat& dst);

 private:
  cv::Mat* mat_;
};
