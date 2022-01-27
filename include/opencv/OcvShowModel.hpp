#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>
#include <iostream>
#include "OcvBaseNode.hpp"
#include "OcvData.hpp"

/* The model dictates the number of inputs and outputs for the Node.
 In this example it has no logic. */
class OcvShowModel : public OcvBaseNode
{
  Q_OBJECT

 public:
  OcvShowModel();

  virtual ~OcvShowModel() {}

 public:
  QString caption() const override { return QString("Image Display"); }

  QString name() const override { return QString("OcvShowModel"); }

  std::shared_ptr<NodeData> outData(PortIndex port) override;
 public slots:
  void SetImage(const QImage &image);

  void SetMat(const cv::Mat &mat);

 public:
  virtual QString modelName() const { return QString("Resulting Image"); }

  QWidget *embeddedWidget() override { return _label; }

  bool resizable() const override { return false; }

  void process();

 protected:
  bool eventFilter(QObject *object, QEvent *event) override;

 private:
  QLabel *_label;

  cv::Mat *mat_;

  cv::Mat *in_mat_;
};
